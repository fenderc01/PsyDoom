#pragma once

//------------------------------------------------------------------------------------------------------------------------------------------
// Rendering and geometry related data structures.
// A lot of these are used by game logic too, in addition to the renderer.
//------------------------------------------------------------------------------------------------------------------------------------------

#include "Doom/doomdef.h"

struct line_t;

// Represents a vertex in a line
struct vertex_t {
    fixed_t     x;
    fixed_t     y;
    int32_t     xx;         // TODO: comment on usage
    int32_t     vx;         // TODO: comment on usage
    int32_t     vy;         // TODO: comment on usage
    int32_t     yy;         // TODO: comment on usage
    int32_t     index;      // TODO: comment on usage
};

static_assert(sizeof(vertex_t) == 28);

// Describes a sector or collection of lines and subsectors
struct sector_t {
    fixed_t                 floorheight;
    fixed_t                 ceilingheight;
    int32_t                 floorpic;
    int32_t                 ceilingpic;
    int16_t                 colorid;
    int16_t                 lightlevel;
    int32_t                 special;
    int32_t                 tag;
    int32_t                 soundtraversed;
    VmPtr<mobj_t>           soundtarget;
    uint32_t                flags;              // TODO: CONFIRM LAYOUT    
    int32_t                 blockbox[4];        // TODO: CONFIRM LAYOUT
    degenmobj_t             soundorg;           // TODO: CONFIRM LAYOUT
    int32_t                 validcount;
    VmPtr<mobj_t>           thinglist;
    VmPtr<void>             specialdata;
    int32_t                 linecount;
    VmPtr<VmPtr<line_t>>    lines;
};

static_assert(sizeof(sector_t) == 92);

// Describes a side of a line
struct side_t {
    fixed_t             textureoffset;
    fixed_t             rowoffset;
    int32_t             toptexture;
    int32_t             bottomtexture;
    int32_t             midtexture;
    VmPtr<sector_t>     sector;
};

static_assert(sizeof(side_t) == 24);

// What type of slope a line has
enum slopetype_t : uint32_t { 
    ST_HORIZONTAL,
    ST_VERTICAL,
    ST_POSITIVE,
    ST_NEGATIVE
};

// Describes a line in the map
struct line_t {
    VmPtr<vertex_t>     vertex1;
    VmPtr<vertex_t>     vertex2;
    fixed_t             dx;             // Precomputed 'v2 - v1' in the x and y directions
    fixed_t             dy;
    int32_t             flags;
    int32_t             special;
    int32_t             tag;
    int32_t             sidenum[2];     // If sidenum[1] is '-1' then the line is one sided
    fixed_t             bbox[4];
    slopetype_t         slopetype;      // Used to simplify some collision detection
    VmPtr<sector_t>     frontsector;
    VmPtr<sector_t>     backsector;
    int32_t             validcount;
    VmPtr<void>         specialdata;    // Used by thinkers doing special logic
    fixed_t             fineangle;      // So sine/cosine can be looked up quicker
};

static_assert(sizeof(line_t) == 76);

// Describes a convex region within a sector
struct subsector_t {
    int16_t     unknown1;   // TODO: find out what this field is
    int16_t     unknown2;   // TODO: find out what this field is
    int16_t     numSegs;
    int16_t     firstSeg;
    int16_t     unknown3;   // TODO: find out what this field is
    int16_t     unknown4;   // TODO: find out what this field is
    int16_t     unknown5;   // TODO: find out what this field is
    int16_t     unknown6;   // TODO: find out what this field is
};

static_assert(sizeof(subsector_t) == 16);

// Describes a segment of a line
struct seg_t {
    VmPtr<vertex_t>     vertex1;
    VmPtr<vertex_t>     vertex2;
    fixed_t             offset;
    angle_t             angle;
    VmPtr<side_t>       sidedef;
    VmPtr<line_t>       linedef;
    VmPtr<sector_t>     frontsector;        // TODO: confirm
    VmPtr<sector_t>     backsector;
    uint32_t            unknown1;           // TODO: find out what this is
    uint32_t            unknown2;           // TODO: find out what this is
};

static_assert(sizeof(seg_t) == 40);
