//
// (C) Copyright 1997-2007 by Autodesk, Inc.
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//
#ifndef __DRAWABLE_H
#define __DRAWABLE_H

#include "rxobject.h"
#include "dbid.h"
#pragma pack (push, 8)

class AcGiDrawableTraits;
class AcGiWorldDraw;
class AcGiViewportDraw;
class AcGsNode;
class AcDbSubentId;

class ADESK_NO_VTABLE AcGiDrawable : public AcRxObject
{
public:

    ACRX_DECLARE_MEMBERS(AcGiDrawable);

    // Combine these flags in the return value
    // of setAttributes for efficiency of implementation
    // it is vital that if you use certain aspects of the
    // API that the correct flags be used. Otherwise the
    // display system may be incorrectly configured for
    // subsequent graphics. kIsCompoundObject gives
    // full access to the AcGi API, enabling the use
    // of draw() and the AcGi primitives together. Enabling
    // this makes the elaboration of an object marginally 
    // slower. So you should use the lowest value appropriate.
    //
    //
    enum SetAttributesFlags
    {
        // Default drawable, just uses acgi primitives and does not use 
        // nested calls to draw()
        kDrawableNone                           =  0, 

        // AcDbEntity derived classes (may require some special processing)
        kDrawableIsAnEntity                     =  1,

        // (block table record) Uses nesting but does not send down additional 
        // primitives. It uses draw() exclusively and makes no calls to the 
        // other AcGi primitives such as circle or shell
        kDrawableUsesNesting                    =  2,

        // You MUST specify this value if you nest entities as a block does.
        kDrawableIsCompoundObject               =  4, 
        
        // Drawable specifies when viewportDraw will be called.  Employ 
        // per-Viewport caching of viewportDraw geometry.  As well, this 
        // drawable does not use worldDraw.
        kDrawableViewIndependentViewportDraw    =  8,

        // If this entity is not visible (AcDbEntity::visibility())
        kDrawableIsInvisible                    =  16,

        // If a compound object has attributes it must specify this value
        kDrawableHasAttributes                  =  32,

        // If the geometry you elaborate is dependent on the regentype; for 
        // instance, if your drawable draws itself as a set of polygons in a 
        // "shaded" regen-mode but as a set of wires in "standard display", 
        // specify this flag
        kDrawableRegenTypeDependantGeometry     =  64,

        // Dimensions receive  special handling, behaving similarly to blocks
        kDrawableIsDimension = (kDrawableIsAnEntity + kDrawableIsCompoundObject + 128),

        // Always regenerate drawable
        kDrawableRegenDraw                      = 256,

        // Drawable has single level of detail for regen type 
        // kAcGiStandardDisplay 
        kDrawableStandardDisplaySingleLOD       = 512,

        // Drawable has single level of detail for regen type 
        // kAcGiShadedDisplay
        kDrawableShadedDisplaySingleLOD         = 1024,

        // Drawable requires viewportDraw be called on every view change.
        kDrawableViewDependentViewportDraw      =  2048,
      
        // Drawable requires unique viewportDraw elaboration for each block path.
        kDrawableBlockDependentViewportDraw     =  4096
    };


    // These are the Drawable types
    //
    enum DrawableType
    {
        kGeometry              = 0, 
        kDistantLight,
        kPointLight,            
        kSpotLight,
        kAmbientLight,
        kSolidBackground,
        kGradientBackground,
        kImageBackground,
        kGroundPlaneBackground,
        kViewport,
        kWebLight,
        kSkyBackground
    };

    // For default attributes
    virtual Adesk::UInt32   setAttributes   (AcGiDrawableTraits * traits)   = 0;

    // For geometry shared between multiple viewports
    virtual Adesk::Boolean  worldDraw       (AcGiWorldDraw * wd)            = 0;

    // For viewport-specific geometry
    virtual void            viewportDraw    (AcGiViewportDraw * vd)         = 0;

    // Persistent/transient
    virtual Adesk::Boolean  isPersistent    (void) const                    = 0;
    virtual AcDbObjectId    id              (void) const                    = 0;

    // Drawable type. 
    virtual DrawableType    drawableType() const { return kGeometry; }

    // Graphics cache
    virtual void            setGsNode       (AcGsNode * gsnode)             = 0;
    virtual AcGsNode*       gsNode          (void) const                    = 0;

    // For ViewIndependentViewportDraw caching
    // return bitwise combination of SetAttributesFlags
    // for now, 3D GS only investigates kDrawableRegenTypeDependantGeometry
    virtual Adesk::UInt32   viewportDrawLogicalFlags (AcGiViewportDraw * vd) { return 0; }
    
    // nMouseFlags are identical to the WM_MOUSEMOVE wParam windows message. See MSDN for those flags, they are provided as is.
    // reset is true if rollover is resetting or leaving your object.
    // return true if you want rollover to track your object, false to ignore it.
    virtual  Adesk::Boolean RolloverHit(Adesk::ULongPtr nSubentId,
                                        Adesk::ULongPtr nMouseFlags,
                                        Adesk::Boolean bReset ) {
                        return Adesk::kFalse; }

   
};

#pragma pack (pop)
#endif // __DRAWABLE_H
