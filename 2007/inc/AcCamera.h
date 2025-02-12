
#pragma once
//
// (C) Copyright 2005-2006 by Autodesk, Inc. 
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
//

#include "acdb.h"
#include "dbmain.h"
#include "dbents.h"

#pragma pack(push, 8)

// The following is part of the code used to export a API
// and/or use the exported API.
//
#pragma warning( disable: 4275 4251 )

#ifdef CAMERADLLIMPEXP
#undef CAMERADLLIMPEXP
#endif
#ifdef ACCAMERA_EXPORTS
#define CAMERADLLIMPEXP __declspec( dllexport )
#else
// Note: we don't use __declspec(dllimport) here, because of the
// "local vtable" problem with msvc.  If you use __declspec(dllimport),
// then, when a client dll does a new on the class, the object's
// vtable pointer points to a vtable allocated in that client
// dll.  If the client dll then passes the object to another dll,
// and the client dll is then unloaded, the vtable becomes invalid
// and any virtual calls on the object will access invalid memory.
//
// By not using __declspec(dllimport), we guarantee that the
// vtable is allocated in the server dll during the ctor and the
// client dll does not overwrite the vtable pointer after calling
// the ctor.  And, since we expect the server dll to remain in
// memory indefinitely, there is no problem with vtables unexpectedly
// going away.
// 
#define CAMERADLLIMPEXP //__declspec( dllimport )
#endif

class AcDbImpCamera;

class CAMERADLLIMPEXP AcDbCamera: public AcDbEntity
{

public:
    //*************************************************************************
    // Constructors and Destructors
    //*************************************************************************
    AcDbCamera ();
    virtual ~AcDbCamera();
    ACDB_DECLARE_MEMBERS(AcDbCamera);

    //*************************************************************************
    // Camera Properties
    //*************************************************************************

    AcDbObjectId view() const; 
    Acad::ErrorStatus	setView(const AcDbObjectId viewId);

    //*************************************************************************
    // Overridden methods from AcDbEntity
    //*************************************************************************
    virtual Acad::ErrorStatus getGripPoints(AcDbGripDataPtrArray& grips,
                                            const double curViewUnitSize,
                                            const int gripSize,
                                            const AcGeVector3d& curViewDir,
                                            const int bitflags) const;

    virtual Acad::ErrorStatus moveGripPointsAt(
        const AcDbVoidPtrArray& gripAppData,
        const AcGeVector3d& offset,
        const int bitflags);
    
    virtual Acad::ErrorStatus	getStretchPoints(
        AcGePoint3dArray&  stretchPoints)
        const;
    virtual Acad::ErrorStatus   moveStretchPointsAt(
        const AcDbIntArray& indices,
        const AcGeVector3d&     offset);
    
    virtual void		list() const;
    
    virtual Acad::ErrorStatus transformBy(const AcGeMatrix3d& xform);
    
    virtual Adesk::Boolean worldDraw(AcGiWorldDraw*	mode);
    virtual void viewportDraw(AcGiViewportDraw* mode);
    virtual Adesk::UInt32 setAttributes(AcGiDrawableTraits* pTraits);
    
    //*************************************************************************
    // Overridden methods from AcDbObject
    //*************************************************************************
    virtual Acad::ErrorStatus   subErase(Adesk::Boolean erasing);
    virtual Acad::ErrorStatus   subOpen(AcDb::OpenMode openMode);
    virtual Acad::ErrorStatus   subClose();

    virtual Acad::ErrorStatus	dwgInFields(AcDbDwgFiler* filer);
    virtual Acad::ErrorStatus	dwgOutFields(AcDbDwgFiler* filer) const;
    
    virtual Acad::ErrorStatus	dxfInFields(AcDbDxfFiler* filer);
    virtual Acad::ErrorStatus	dxfOutFields(AcDbDxfFiler* filer) const;

    virtual Acad::ErrorStatus deepClone(AcDbObject* pOwnerObject,
        AcDbObject*& pClonedObject,
        AcDbIdMapping& idMap,
        Adesk::Boolean isPrimary
        = Adesk::kTrue) const;
    
    virtual Acad::ErrorStatus wblockClone(AcRxObject* pOwnerObject,
        AcDbObject*& pClonedObject,
        AcDbIdMapping& idMap,
        Adesk::Boolean isPrimary
        = Adesk::kTrue) const;
    
    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;

    virtual Acad::ErrorStatus highlight(const AcDbFullSubentPath& subId = kNullSubent, 
                                        const Adesk::Boolean highlightAll = Adesk::kFalse) const;
    virtual Acad::ErrorStatus unhighlight(const AcDbFullSubentPath& subId = kNullSubent, 
                                          const Adesk::Boolean highlightAll = Adesk::kFalse) const;

private:
    friend class AcDbImpCamera;
    AcDbImpCamera* pImp;
};



#pragma pack (pop)