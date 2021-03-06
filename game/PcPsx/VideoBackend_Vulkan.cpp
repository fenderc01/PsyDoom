#if PSYDOOM_VULKAN_RENDERER

#include "VideoBackend_Vulkan.h"

#include "Asserts.h"
#include "LogicalDevice.h"
#include "PhysicalDeviceSelection.h"
#include "Texture.h"
#include "VkFuncs.h"
#include "Vulkan/VRenderer.h"
#include "VulkanInstance.h"
#include "WindowSurface.h"

#include <SDL.h>
#include <SDL_vulkan.h>

BEGIN_NAMESPACE(Video)

//------------------------------------------------------------------------------------------------------------------------------------------
// Checks whether the Vulkan video backend is supported
//------------------------------------------------------------------------------------------------------------------------------------------
bool VideoBackend_Vulkan::isBackendSupported() noexcept {
    // Must be able to load the Vulkan library or have it embedded in the application
    if (SDL_Vulkan_LoadLibrary(nullptr) != 0)
        return false;
        
    // Must be able to retrieve Vulkan functions
    if (!SDL_Vulkan_GetVkGetInstanceProcAddr())
        return false;

    // Create a temporary (headless) API instance and make sure we can pick a suitable device from it.
    // It's possible that a Vulkan driver might be installed on the system but no valid devices are present.
    //
    // Note: have to use the headless checks because at this point we don't have an SDL window created.
    // This function is used to DECIDE what type of SDL Window to create, so we can't check surface output capabilities yet...
    vgl::VkFuncs vkFuncs = {};
    vgl::VulkanInstance vulkanInstance(vkFuncs);

    if (!vulkanInstance.init(nullptr))
        return false;

    const std::vector<vgl::PhysicalDevice>& physicalDevices = vulkanInstance.getPhysicalDevices();
    const vgl::PhysicalDevice* const pSelectedDevice = vgl::PhysicalDeviceSelection::selectBestHeadlessDevice(
        physicalDevices,
        VRenderer::isHeadlessPhysicalDeviceSuitable
    );

    if (!pSelectedDevice)
        return false;

    // Attempt to workaround issue #8 on Github: failing to create the PSX VRAM texture on a AMD Radeon HD 8790M.
    // The driver for this card seems to say that the VRAM texture format (and features) are supported but texture creation fails in spite of this.
    // It might be that what the driver reports as supported isn't actually supported in some cases. Workaround this by doing a dry run of the
    // creation of this texture; it's the most odd format used by PsyDoom so hopefully the check can catch issues with other drivers too...
    vgl::LogicalDevice logicalDevice(vkFuncs);

    if (!logicalDevice.init(*pSelectedDevice, nullptr))
        return false;

    vgl::Texture dummyVramTexture;

    if (!dummyVramTexture.initAs2dTexture(logicalDevice, VK_FORMAT_R16_UINT, 1024, 512))
        return false;

    // All good if we get to here - this device works!
    return true;
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Creates the backend with stuff for the Vulkan and classic renderers uninitialized
//------------------------------------------------------------------------------------------------------------------------------------------
VideoBackend_Vulkan::VideoBackend_Vulkan() noexcept 
    : mpSdlWindow(nullptr)
{
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Ensures everything is cleaned up
//------------------------------------------------------------------------------------------------------------------------------------------
VideoBackend_Vulkan::~VideoBackend_Vulkan() noexcept {
    destroyRenderers();
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Get the window create flags required for an SDL video backend window
//------------------------------------------------------------------------------------------------------------------------------------------
uint32_t VideoBackend_Vulkan::getSdlWindowCreateFlags() noexcept {
    // Want a Vulkan window only
    return SDL_WINDOW_VULKAN;
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Initializes the SDL renderer used by this backend
//------------------------------------------------------------------------------------------------------------------------------------------
void VideoBackend_Vulkan::initRenderers(SDL_Window* const pSdlWindow) noexcept {
    // Save the SDL window for later use
    ASSERT(pSdlWindow);
    mpSdlWindow = pSdlWindow;

    // Initialize the game's core Vulkan renderer module and begin a frame
    VRenderer::init();
    VRenderer::beginFrame();
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Cleans up and destroys the SDL renderer used by this video backend
//------------------------------------------------------------------------------------------------------------------------------------------
void VideoBackend_Vulkan::destroyRenderers() noexcept {
    VRenderer::destroy();
    mpSdlWindow = nullptr;
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Displays the output from the Vulkan based renderer (classic, or new) to the screen
//------------------------------------------------------------------------------------------------------------------------------------------
void VideoBackend_Vulkan::displayFramebuffer() noexcept {
    VRenderer::endFrame();
    VRenderer::beginFrame();
}

END_NAMESPACE(Video)

#endif  // #if PSYDOOM_VULKAN_RENDERER
