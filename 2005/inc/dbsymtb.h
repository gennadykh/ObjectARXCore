#ifndef AD_DBSYMTB_H
#define AD_DBSYMTB_H
//
// Copyright 1997-2003 by Autodesk, Inc.
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
// DESCRIPTION: Exported protocol for AutoCAD's built in symbol
//              tables, their table  specific record types, and
//              their iterators.

#include "dbmain.h"
#include "dbdict.h"
#include "dbdate.h"
#include "gevec2d.h"

#pragma pack(push, 8)

#ifdef target
# undef target 
#endif

class AcDbSortentsTable;
class AcDbSymbolTableIterator;
class AcDbSymbolTableRecord;
class AcGsView;

class ADESK_NO_VTABLE AcDbSymbolTable: public AcDbObject
//
// (... and Subclasses)
//
// Note that there is both overloading of functions within each
// class defined by these macros and overriding of non virtual
// functions between classes.  The overriding of these functions
// is necessary to allow some member functions to take arguments
// that are appropriate for a given table.
//
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSymbolTable);
    AcDbSymbolTable();
    virtual ~AcDbSymbolTable();

    typedef AcDbSymbolTableRecord RecordType;

    Acad::ErrorStatus getAt (const char* entryName,
                             AcDbSymbolTableRecord*& pRec,
                             AcDb::OpenMode openMode,
                             bool openErasedRec = false) const;
    Acad::ErrorStatus getAt (const char* entryName,
                             AcDbObjectId& recordId,
                             bool getErasedRecord = false) const;
    bool              has(const char* name) const;
    bool              has(AcDbObjectId id) const;
    Acad::ErrorStatus newIterator(AcDbSymbolTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Acad::ErrorStatus add(AcDbSymbolTableRecord* pRecord);
    Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbSymbolTableRecord* pRecord);

};

class AcDbBlockTableRecord;
class AcDbBlockTableIterator;

class AcDbBlockTable: public AcDbSymbolTable
{
public:
    ACDB_DECLARE_MEMBERS(AcDbBlockTable);
    AcDbBlockTable();
    virtual ~AcDbBlockTable();

    typedef AcDbBlockTableRecord RecordType;

    Acad::ErrorStatus getAt (const char* entryName,
                             AcDbBlockTableRecord*& pRec,
                             AcDb::OpenMode openMode,
                             bool openErasedRec = false) const;
    Acad::ErrorStatus getAt (const char* entryName,
                             AcDbObjectId& recordId,
                             bool getErasedRec = false) const;
    bool              has   (const char* name) const;
    bool              has   (AcDbObjectId id) const;
    Acad::ErrorStatus newIterator(AcDbBlockTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Acad::ErrorStatus add   (AcDbBlockTableRecord* pRecord);
    Acad::ErrorStatus add   (AcDbObjectId& recordId, AcDbBlockTableRecord* pRecord);

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class AcDbLayerTableRecord;
class AcDbLayerTableIterator;

class AcDbLayerTable: public AcDbSymbolTable
{
public:
    ACDB_DECLARE_MEMBERS(AcDbLayerTable);
    AcDbLayerTable();
    virtual ~AcDbLayerTable();

    typedef AcDbLayerTableRecord RecordType;

    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbLayerTableRecord*& pRec,
                            AcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbObjectId& recordId,
                            bool getErasedRecord = false) const;
    bool              has  (const char* name) const;
    bool              has  (AcDbObjectId id) const;
    Acad::ErrorStatus newIterator(AcDbLayerTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Acad::ErrorStatus add (AcDbLayerTableRecord* pRecord);
    Acad::ErrorStatus add (AcDbObjectId& recordId, AcDbLayerTableRecord* pRecord);

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;

    void generateUsageData();
};

class AcDbTextStyleTableRecord;
class AcDbTextStyleTableIterator;

class AcDbTextStyleTable: public AcDbSymbolTable
{
public:
    ACDB_DECLARE_MEMBERS(AcDbTextStyleTable);
    AcDbTextStyleTable();
    virtual ~AcDbTextStyleTable();

    typedef AcDbTextStyleTableRecord RecordType;

    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbTextStyleTableRecord*& pRec,
                            AcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Acad::ErrorStatus getAt (const char* entryName,
                             AcDbObjectId& recordId,
                             bool getErasedRecord = false) const;
    bool              has   (const char* name) const;
    bool              has   (AcDbObjectId id) const;
    Acad::ErrorStatus newIterator(AcDbTextStyleTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Acad::ErrorStatus add   (AcDbTextStyleTableRecord* pRecord);
    Acad::ErrorStatus add   (AcDbObjectId&  recordId,
        AcDbTextStyleTableRecord* pRecord);

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class AcDbLinetypeTableRecord;
class AcDbLinetypeTableIterator;

class AcDbLinetypeTable: public AcDbSymbolTable
{
public:
    ACDB_DECLARE_MEMBERS(AcDbLinetypeTable);
    AcDbLinetypeTable();
    virtual ~AcDbLinetypeTable();

    typedef AcDbLinetypeTableRecord RecordType;

    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbLinetypeTableRecord*& pRec,
                            AcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbObjectId& recordId,
                            bool getErasedRec = false) const;
    bool              has  (const char* name) const;
    bool              has  (AcDbObjectId id) const;
    Acad::ErrorStatus newIterator(AcDbLinetypeTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Acad::ErrorStatus add  (AcDbLinetypeTableRecord* pRecord);
    Acad::ErrorStatus add  (AcDbObjectId& recordId,
        AcDbLinetypeTableRecord* pRecord);

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class AcDbAbstractViewTableRecord;
class AcDbAbstractViewTableIterator;

class ADESK_NO_VTABLE AcDbAbstractViewTable: public AcDbSymbolTable
{
public:
    ACDB_DECLARE_MEMBERS(AcDbAbstractViewTable);
    AcDbAbstractViewTable();
    virtual ~AcDbAbstractViewTable();
    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbAbstractViewTableRecord*& pRec,
                            AcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbObjectId& recordId,
                            bool getErasedRecord = false) const;
    bool              has  (const char* name) const;
    bool              has  (AcDbObjectId id) const;
    Acad::ErrorStatus newIterator(AcDbAbstractViewTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Acad::ErrorStatus add  (AcDbAbstractViewTableRecord* pRecord);
    Acad::ErrorStatus add  (AcDbObjectId&  recordId,
        AcDbAbstractViewTableRecord* pRecord);
};

class AcDbViewTableRecord;
class AcDbViewTableIterator;

class AcDbViewTable: public AcDbAbstractViewTable
{
public:
    ACDB_DECLARE_MEMBERS(AcDbViewTable);
    AcDbViewTable();
    virtual ~AcDbViewTable();

    typedef AcDbViewTableRecord RecordType;

    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbViewTableRecord*& pRec,
                            AcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbObjectId& recordId,
                            bool getErasedRec = false) const;
    bool              has  (const char* name) const;
    bool              has  (AcDbObjectId id) const;
    Acad::ErrorStatus newIterator(AcDbViewTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Acad::ErrorStatus add  (AcDbViewTableRecord* pRecord);
    Acad::ErrorStatus add  (AcDbObjectId&  recordId,
        AcDbViewTableRecord* pRecord);

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class AcDbUCSTableRecord;
class AcDbUCSTableIterator;

class AcDbUCSTable: public AcDbSymbolTable
{
public:
    ACDB_DECLARE_MEMBERS(AcDbUCSTable);
    AcDbUCSTable();
    virtual ~AcDbUCSTable();

    typedef AcDbUCSTableRecord RecordType;

    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbUCSTableRecord*& pRec,
                            AcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbObjectId& recordId,
                            bool getErasedRecord = false) const;
    bool              has  (const char* name) const;
    bool              has  (AcDbObjectId id) const;
    Acad::ErrorStatus newIterator(AcDbUCSTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Acad::ErrorStatus add  (AcDbUCSTableRecord* pRecord);
    Acad::ErrorStatus add  (AcDbObjectId&  recordId,
        AcDbUCSTableRecord* pRecord);

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class AcDbViewportTableRecord;
class AcDbViewportTableIterator;

class AcDbViewportTable: public AcDbAbstractViewTable
{
public:
    ACDB_DECLARE_MEMBERS(AcDbViewportTable);
    AcDbViewportTable();
    virtual ~AcDbViewportTable();

    typedef AcDbViewportTableRecord RecordType;

    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbViewportTableRecord*& pRec,
                            AcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbObjectId& recordId,
                            bool getErasedRecord = false) const;
    bool              has  (const char* name) const;
    bool              has  (AcDbObjectId id) const;
    Acad::ErrorStatus newIterator(AcDbViewportTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Acad::ErrorStatus add  (AcDbViewportTableRecord* pRecord);
    Acad::ErrorStatus add  (AcDbObjectId& recordId,
        AcDbViewportTableRecord* pRecord);

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class AcDbRegAppTableRecord;
class AcDbRegAppTableIterator;

class AcDbRegAppTable: public AcDbSymbolTable
{
public:
    ACDB_DECLARE_MEMBERS(AcDbRegAppTable);
    AcDbRegAppTable();
    virtual ~AcDbRegAppTable();

    typedef AcDbRegAppTableRecord RecordType;

    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbRegAppTableRecord*& pRec,
                            AcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Acad::ErrorStatus getAt(const char* entryName,
                            AcDbObjectId& recordId,
                            bool getErasedRec = false) const;
    bool              has  (const char* name) const;
    bool              has  (AcDbObjectId id) const;
    Acad::ErrorStatus newIterator(AcDbRegAppTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Acad::ErrorStatus   add     (AcDbRegAppTableRecord* pRecord);
    Acad::ErrorStatus   add     (AcDbObjectId&  recordId,
        AcDbRegAppTableRecord* pRecord);

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class AcDbDimStyleTableRecord;
class AcDbDimStyleTableIterator;

class AcDbDimStyleTable: public AcDbSymbolTable
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDimStyleTable);
    AcDbDimStyleTable();
    virtual ~AcDbDimStyleTable();

    typedef AcDbDimStyleTableRecord RecordType;

    Acad::ErrorStatus   getAt   (const char* entryName,
                                 AcDbDimStyleTableRecord*& pRec,
                                 AcDb::OpenMode openMode,
                                 bool openErasedRec = false) const;
    Acad::ErrorStatus   getAt   (const char* entryName,
                                 AcDbObjectId& recordId,
                                 bool getErasedRec = false) const;
    bool                has     (const char* name) const;
    bool                has     (AcDbObjectId id) const;
    Acad::ErrorStatus   newIterator(AcDbDimStyleTableIterator*& pIterator,
                                    bool atBeginning = true,
                                    bool skipDeleted = true) const;
    Acad::ErrorStatus   add     (AcDbDimStyleTableRecord* pRecord);
    Acad::ErrorStatus   add     (AcDbObjectId&  recordId,
        AcDbDimStyleTableRecord* pRecord);

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

///// AcDbSymbolTableIterator
//
// This class is responsible for iterating over the records in a symbol
// table.
//
// This is a completely "generic" symbol table iterator in that it can 
// be used to iterate over the contents of any AcDbSymbolTable subclass.
// However, symbol table specific iterators are defined below.
//
// One major item of note.  The creation of one of these iterators
// requires the opening (for read) of the table being iterated over.
// This read stays in effect until the iterator is destroyed.
//
class AcDbSymbolTableIterator
{
public:
    virtual ~AcDbSymbolTableIterator();

    void                start   (bool atBeginning = true,
                                 bool skipDeleted = true);

    bool                done    () const;


    Acad::ErrorStatus   getRecordId(AcDbObjectId& id) const;

    Acad::ErrorStatus   getRecord(AcDbSymbolTableRecord*& pRecord,
                                 AcDb::OpenMode openMode,
                                 bool openErasedRec = false) const;

    void                step    (bool forward = true,
                                 bool skipDeleted = true);

    Acad::ErrorStatus   seek    (AcDbObjectId id);

    Acad::ErrorStatus   seek    (const AcDbSymbolTableRecord* pRecord);
protected:
    void* mpImp;
    AcDbSymbolTableIterator();
    friend AcDbSymbolTable;
};

class AcDbBlockTableIterator : public AcDbSymbolTableIterator
{
public:
    Acad::ErrorStatus getRecord(AcDbBlockTableRecord*& pRecord,
        AcDb::OpenMode openMode, bool openErasedRec = false) const;
    Acad::ErrorStatus seek(AcDbObjectId id);
    Acad::ErrorStatus seek(const AcDbBlockTableRecord* pRecord);

protected:
    AcDbBlockTableIterator();
    friend class AcDbBlockTable;
};

class AcDbLayerTableIterator : public AcDbSymbolTableIterator
{
public:
    Acad::ErrorStatus getRecord(AcDbLayerTableRecord*& pRecord,
        AcDb::OpenMode openMode, bool openErasedRec = false) const;
    Acad::ErrorStatus seek(AcDbObjectId id);
    Acad::ErrorStatus seek(const AcDbLayerTableRecord* pRecord);

protected:
    AcDbLayerTableIterator();
    friend class AcDbLayerTable;
};

class AcDbTextStyleTableIterator : public AcDbSymbolTableIterator
{
public:
    Acad::ErrorStatus getRecord(AcDbTextStyleTableRecord*& pRecord,
        AcDb::OpenMode openMode, bool openErasedRec = false) const;
    Acad::ErrorStatus seek(AcDbObjectId id);
    Acad::ErrorStatus seek(const AcDbTextStyleTableRecord* pRecord);

protected:
    AcDbTextStyleTableIterator();
    friend class AcDbTextStyleTable;
};

class AcDbLinetypeTableIterator : public AcDbSymbolTableIterator
{
public:
    Acad::ErrorStatus getRecord(AcDbLinetypeTableRecord*& pRecord,
        AcDb::OpenMode openMode, bool openErasedRec = false) const;
    Acad::ErrorStatus seek(AcDbObjectId id);
    Acad::ErrorStatus seek(const AcDbLinetypeTableRecord* pRecord);

protected:
    AcDbLinetypeTableIterator();
    friend class AcDbLinetypeTable;
};

class AcDbAbstractViewTableIterator : public AcDbSymbolTableIterator
{
public:
    Acad::ErrorStatus getRecord(AcDbAbstractViewTableRecord*& pRecord,
        AcDb::OpenMode openMode, bool openErasedRec = false) const;
    Acad::ErrorStatus seek(AcDbObjectId id);
    Acad::ErrorStatus seek(const AcDbAbstractViewTableRecord* pRecord);

protected:
    AcDbAbstractViewTableIterator();
    friend class AcDbAbstractViewTable;
};

class AcDbViewTableIterator : public AcDbAbstractViewTableIterator
{
public:
    Acad::ErrorStatus getRecord(AcDbViewTableRecord*& pRecord,
        AcDb::OpenMode openMode, bool openErasedRec = false) const;
    Acad::ErrorStatus seek(AcDbObjectId id);
    Acad::ErrorStatus seek(const AcDbViewTableRecord* pRecord);

protected:
    AcDbViewTableIterator();
    friend class AcDbViewTable;
};

class AcDbUCSTableIterator : public AcDbSymbolTableIterator
{
public:
    Acad::ErrorStatus getRecord(AcDbUCSTableRecord*& pRecord,
        AcDb::OpenMode openMode, bool openErasedRec = false) const;
    Acad::ErrorStatus seek(AcDbObjectId id);
    Acad::ErrorStatus seek(const AcDbUCSTableRecord* pRecord);

protected:
    AcDbUCSTableIterator();
    friend class AcDbUCSTable;
};

class AcDbViewportTableIterator : public AcDbAbstractViewTableIterator
{
public:
    Acad::ErrorStatus getRecord(AcDbViewportTableRecord*& pRecord,
        AcDb::OpenMode openMode, bool openErasedRec = false) const;
    Acad::ErrorStatus seek(AcDbObjectId id);
    Acad::ErrorStatus seek(const AcDbViewportTableRecord* pRecord);

protected:
    AcDbViewportTableIterator();
    friend class AcDbViewportTable;
};

class AcDbRegAppTableIterator : public AcDbSymbolTableIterator
{
public:
    Acad::ErrorStatus getRecord(AcDbRegAppTableRecord*& pRecord,
        AcDb::OpenMode openMode, bool openErasedRec = false) const;
    Acad::ErrorStatus seek(AcDbObjectId id);
    Acad::ErrorStatus seek(const AcDbRegAppTableRecord* pRecord);

protected:
    AcDbRegAppTableIterator();
    friend class AcDbRegAppTable;
};

class AcDbDimStyleTableIterator : public AcDbSymbolTableIterator
{
public:
    Acad::ErrorStatus getRecord(AcDbDimStyleTableRecord*& pRecord,
        AcDb::OpenMode openMode, bool openErasedRec = false) const;
    Acad::ErrorStatus seek(AcDbObjectId id);
    Acad::ErrorStatus seek(const AcDbDimStyleTableRecord* pRecord);

protected:
    AcDbDimStyleTableIterator();
    friend class AcDbDimStyleTable;
};

class ADESK_NO_VTABLE AcDbSymbolTableRecord: public  AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSymbolTableRecord);
    AcDbSymbolTableRecord();
    virtual ~AcDbSymbolTableRecord();

    typedef AcDbSymbolTable TableType;

    Acad::ErrorStatus getName(char*& pName) const;
    Acad::ErrorStatus getName(const char*& pName) const;
    Acad::ErrorStatus setName(const char* pName);

    bool isDependent() const;

    bool isResolved() const;
};


class AcDbBlockTableRecordIterator
{
public:
    virtual ~AcDbBlockTableRecordIterator();

    void              start (bool atBeginning = true,
                             bool skipDeleted = true);

    bool              done  () const;

    Acad::ErrorStatus getEntityId (AcDbObjectId& entityId) const;

    Acad::ErrorStatus getEntity(AcDbEntity*& pEntity, AcDb::OpenMode openMode,
                                bool openErasedEntity = false) const;

    AcDbBlockTableRecord* blockTableRecord() const;

    void              step (bool forward = true,
                            bool skipDeleted = true);

    Acad::ErrorStatus seek (AcDbObjectId id);

    Acad::ErrorStatus seek (const AcDbEntity* pEntity);

protected:
    class AcDbImpBlockTableRecordIterator* mpImp;
private:
    AcDbBlockTableRecordIterator();
    friend class AcDbImpBlockTableRecord;
};


// This class will be removed in the next release.   Instead, use
// AcDbBlockTableRecord::getBlockReferenceIds().
//
class AcDbBlockReferenceIdIterator
{
public:
    ~AcDbBlockReferenceIdIterator();

    void              start () { mPos = 0; }
        
    bool              done  () const { return mPos >= mAry.length(); }

    Acad::ErrorStatus getBlockReferenceId (AcDbObjectId& id) const;

    Acad::ErrorStatus getDatabase (AcDbDatabase*& pDb) const;

    Acad::ErrorStatus getBlockReference(AcDbBlockReference*& pBlkRef,
                        AcDb::OpenMode openMode, bool openErasedEntity = false) const;

    void              step () { mPos++; }

    Acad::ErrorStatus seek (AcDbObjectId id);

private:
    AcDbBlockReferenceIdIterator();
    friend class AcDbBlockTableRecord;

    int               mPos;
    AcDbObjectIdArray mAry;
};

class AcDbBlockTableRecord: public  AcDbSymbolTableRecord
{
public:
    ACDB_DECLARE_MEMBERS(AcDbBlockTableRecord);

    AcDbBlockTableRecord();
    virtual ~AcDbBlockTableRecord();

    typedef AcDbBlockTable TableType;
    typedef AcArray<Adesk::UInt8> PreviewIcon;

    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const;
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const;

    Acad::ErrorStatus appendAcDbEntity(AcDbEntity* pEntity);

    Acad::ErrorStatus appendAcDbEntity(AcDbObjectId& pOutputId,
        AcDbEntity* pEntity);

    Acad::ErrorStatus newIterator(
        AcDbBlockTableRecordIterator*& pIterator,
        bool atBeginning = true,
        bool skipDeleted = true) const;

    Acad::ErrorStatus comments(char*& pString) const;
    Acad::ErrorStatus comments(const char*& pString) const;
    Acad::ErrorStatus setComments(const char* pString);

    Acad::ErrorStatus pathName(char*& pPath) const;
    Acad::ErrorStatus pathName(const char*& pPath) const;
    Acad::ErrorStatus setPathName(const char* pathStr);
 
    AcGePoint3d       origin() const;
    Acad::ErrorStatus setOrigin(const AcGePoint3d& pt);

    Acad::ErrorStatus openBlockBegin(AcDbBlockBegin*& pBlockBegin,
                                     AcDb::OpenMode   openMode);
 
    Acad::ErrorStatus openBlockEnd(AcDbBlockEnd*& pBlockEnd,
                                   AcDb::OpenMode openMode);

    bool              hasAttributeDefinitions() const;

    bool              hasPreviewIcon() const;
    Acad::ErrorStatus getPreviewIcon(PreviewIcon &previewIcon) const;
    Acad::ErrorStatus setPreviewIcon(const PreviewIcon &previewIcon);

    bool              isAnonymous() const;

    bool              isFromExternalReference() const;

    bool              isFromOverlayReference() const;

    bool              isLayout() const;

    AcDbObjectId      getLayoutId() const;
    Acad::ErrorStatus setLayoutId(AcDbObjectId);


    Acad::ErrorStatus newBlockReferenceIdIterator(
        AcDbBlockReferenceIdIterator*& pIter) const;

    // AcDbBlockReferenceIdIterator will be going away. 
    // Use getBlockReferenceIds() instead.
    //
    Acad::ErrorStatus getBlockReferenceIds(AcDbObjectIdArray& ids,
                                           bool bDirectOnly = true,
                                           bool bForceValidity = false); 

    Acad::ErrorStatus getErasedBlockReferenceIds(AcDbObjectIdArray&);

    // getSortentsTable 
    //
    // Returns the sortents table opened as requested, sparing the caller
    // the work of getting the extension dictionary and looking the sortents
    // table up in it.
    // If the dictionary is successfully opened and returned, it is the caller�s
    // responsibility to close it.
    //
    // ErrorStatus returns errors if the sortents dictionary cannot be opened,
    //             doesn�t exist, and createIfNecessary
    //             is false, or if createIfNecessary is true, but
    //             the BTR is not open for write, or if its
    //             extension dictionary could not be created or
    //             opened.
    //                            
    Acad::ErrorStatus
    getSortentsTable(AcDbSortentsTable*& pSortents,
                     AcDb::OpenMode openMode,
                     bool createIfNecessary=false);

    AcDbDatabase*     xrefDatabase(bool incUnres = false) const;

    bool              isUnloaded() const;
    Acad::ErrorStatus setIsUnloaded(bool isUnloaded);

    AcDb::XrefStatus  xrefStatus() const;

    // Drawable API
    //
    AcGiDrawable*     drawable();
    Adesk::UInt32     setAttributes(AcGiDrawableTraits* pTraits);
    Adesk::Boolean    worldDraw(AcGiWorldDraw* pWd);
    void              viewportDraw(AcGiViewportDraw* pVd);
    void              setGsNode(AcGsNode* pNode);
    AcGsNode*         gsNode() const;

    virtual Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion ver,
                                               AcDbObject*& replaceObj,
                                               AcDbObjectId& replaceId,
                                               Adesk::Boolean& exchangeXData);
    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;

    virtual Acad::ErrorStatus assumeOwnershipOf(AcArray <AcDbObjectId> entitiesToMove);
};

class AcDbLayerTableRecord: public  AcDbSymbolTableRecord
{
public:
    ACDB_DECLARE_MEMBERS(AcDbLayerTableRecord);

    AcDbLayerTableRecord();
    virtual ~AcDbLayerTableRecord();

    typedef AcDbLayerTable TableType;

    bool              isFrozen() const;
    Acad::ErrorStatus setIsFrozen(bool frozen);

    bool              isOff() const;
    void              setIsOff(bool off);

    bool              VPDFLT() const;
    void              setVPDFLT(bool frozen);

    bool              isLocked() const;
    void              setIsLocked(bool locked);

    AcCmColor         color() const;
    void              setColor(const AcCmColor &color);
    AcCmEntityColor   entityColor(void) const;

    AcCmTransparency  transparency(void) const;
    Acad::ErrorStatus setTransparency(const AcCmTransparency& trans);

    AcDbObjectId      linetypeObjectId() const;
    void              setLinetypeObjectId(AcDbObjectId id);

    enum { kDxfLayerPlotBit = AcDb::kDxfBool };
    bool              isPlottable() const;
    Acad::ErrorStatus setIsPlottable(bool plot);

    AcDb::LineWeight  lineWeight() const;
    Acad::ErrorStatus setLineWeight(AcDb::LineWeight weight);

    char*             plotStyleName() const;
    AcDbObjectId      plotStyleNameId() const;
    Acad::ErrorStatus setPlotStyleName(const char* newName);
    Acad::ErrorStatus setPlotStyleName(const AcDbObjectId& newId);

    // Drawable API
    //
    AcGiDrawable*     drawable();
    Adesk::UInt32     setAttributes(AcGiDrawableTraits* pTraits);
    Adesk::Boolean    worldDraw(AcGiWorldDraw* pWd);
    void              viewportDraw(AcGiViewportDraw* pVd);
    void              setGsNode(AcGsNode* pNode);
    AcGsNode*         gsNode() const;

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;

    bool              isInUse() const;
    char*             description() const;
    Acad::ErrorStatus setDescription(const char* description);
};

// Utility for changing Layer Table Records in the Current Drawing
Acad::ErrorStatus applyCurDwgLayerTableChanges();

// AcDbTextStyleTableRecord:

class AcDbTextStyleTableRecord: public  AcDbSymbolTableRecord
{
public:
    ACDB_DECLARE_MEMBERS(AcDbTextStyleTableRecord);

    AcDbTextStyleTableRecord();
    virtual ~AcDbTextStyleTableRecord();

    typedef AcDbTextStyleTable TableType;

    Adesk::Boolean isShapeFile() const;
    void setIsShapeFile(Adesk::Boolean shape);

    Adesk::Boolean isVertical() const;
    void setIsVertical(Adesk::Boolean vertical);

    double textSize() const;
    Acad::ErrorStatus setTextSize(double size);

    double xScale() const;
    Acad::ErrorStatus setXScale(double xScale);

    double obliquingAngle() const;
    Acad::ErrorStatus setObliquingAngle(double obliquingAngle);

    Adesk::UInt8 flagBits() const;
    void setFlagBits(Adesk::UInt8 flagBits);

    double priorSize() const;
    Acad::ErrorStatus setPriorSize(double priorSize);

    Acad::ErrorStatus fileName(char*& fileName) const;
    Acad::ErrorStatus fileName(const char*& fileName) const;
    Acad::ErrorStatus setFileName(const char* fileName);

    Acad::ErrorStatus bigFontFileName(char*& fileName) const;
    Acad::ErrorStatus bigFontFileName(const char*& fileName) const;
    Acad::ErrorStatus setBigFontFileName(const char* fileName);

    Acad::ErrorStatus setFont(const char* pTypeface, Adesk::Boolean bold, 
        Adesk::Boolean italic, int charset, int pitchAndFamily);
    Acad::ErrorStatus font   (char*& pTypeface, Adesk::Boolean& bold, Adesk::Boolean& italic,
                              int& charset, int& pitchAndFamily) const;
    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class AcDbLinetypeTableRecord: public  AcDbSymbolTableRecord
{
public:
    ACDB_DECLARE_MEMBERS(AcDbLinetypeTableRecord);

    AcDbLinetypeTableRecord();
    virtual ~AcDbLinetypeTableRecord();

    typedef AcDbLinetypeTable TableType;

    Acad::ErrorStatus comments(char*& pString) const;
    Acad::ErrorStatus comments(const char*& pString) const;
    Acad::ErrorStatus setComments(const char* pString);

    Acad::ErrorStatus asciiDescription(char*& pString) const
                      { return comments(pString); }
    Acad::ErrorStatus asciiDescription(const char*& pString) const
                      { return comments(pString); }
    Acad::ErrorStatus setAsciiDescription(const char* pString)
                      { return setComments(pString); }

    double patternLength() const;
    void   setPatternLength(double patternLength);

    int    numDashes() const;
    void   setNumDashes(int count);

    double dashLengthAt(int index) const;
    void   setDashLengthAt(int index , double value);

    AcDbObjectId shapeStyleAt(int index) const;
    void         setShapeStyleAt(int index, AcDbObjectId id);

    int    shapeNumberAt(int index) const;
    void   setShapeNumberAt(int index, int shapeNumber);

    AcGeVector2d shapeOffsetAt(int index) const;
    void         setShapeOffsetAt(int index, const AcGeVector2d& offset);

    double shapeScaleAt(int index) const;
    void   setShapeScaleAt(int index, double scale);

    bool isScaledToFit() const;
    void           setIsScaledToFit(bool scaledToFit);

    bool shapeIsUcsOrientedAt(int index) const;
    void           setShapeIsUcsOrientedAt(int index, bool isUcsOriented);

    double         shapeRotationAt(int index) const;
    void           setShapeRotationAt(int index, double rotation);

    Acad::ErrorStatus textAt(int index, char*& text) const;
    Acad::ErrorStatus textAt(int index, const char*& text) const;
    Acad::ErrorStatus setTextAt(int index, const char* text);

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ADESK_NO_VTABLE AcDbAbstractViewTableRecord: public  AcDbSymbolTableRecord
{
public:
    ACDB_DECLARE_MEMBERS(AcDbAbstractViewTableRecord);

    AcDbAbstractViewTableRecord();
    virtual ~AcDbAbstractViewTableRecord();

    enum RenderMode {
        k2DOptimized,
        kWireframe,
        kHiddenLine,
        kFlatShaded,
        kGouraudShaded,
        kFlatShadedWithWireframe,
        kGouraudShadedWithWireframe
    };

    AcGePoint2d    centerPoint() const;
    void           setCenterPoint(const AcGePoint2d&);

    double         height() const;
    void           setHeight(double height);

    double         width() const;
    void           setWidth(double width);

    AcGePoint3d    target() const;
    void           setTarget(const AcGePoint3d& target);

    AcGeVector3d   viewDirection() const;
    void           setViewDirection(const AcGeVector3d& viewDirection);

    double         viewTwist() const;
    void           setViewTwist(double angle);

    double         lensLength() const;
    void           setLensLength(double length);

    double         frontClipDistance() const;
    void           setFrontClipDistance(double distance);

    double         backClipDistance() const;
    void           setBackClipDistance(double distance);

    bool           perspectiveEnabled() const;
    void           setPerspectiveEnabled(bool enabled);

    bool           frontClipEnabled() const;
    void           setFrontClipEnabled(bool enabled);

    bool           backClipEnabled() const;
    void           setBackClipEnabled(bool enabled);

    bool           frontClipAtEye() const;
    void           setFrontClipAtEye(bool atEye);

    void           setRenderMode(RenderMode mode);
    RenderMode     renderMode() const;

    // UCS query methods.
    //
    Acad::ErrorStatus getUcs            ( AcGePoint3d& origin,
                                          AcGeVector3d& xAxis,
                                          AcGeVector3d& yAxis ) const;
    bool              isUcsOrthographic ( AcDb::OrthographicView& view ) const;
    AcDbObjectId      ucsName           () const;
    double            elevation         () const;

    // UCS set methods.
    //
    Acad::ErrorStatus setUcs        ( const AcGePoint3d& origin,
                                      const AcGeVector3d& xAxis,
                                      const AcGeVector3d& yAxis );
    Acad::ErrorStatus setUcs        ( AcDb::OrthographicView view );
    Acad::ErrorStatus setUcs        ( const AcDbObjectId& ucsId );
    Acad::ErrorStatus setUcsToWorld ();
    Acad::ErrorStatus setElevation  ( double elev );
 
    // Orthographic view methods.
    //
    bool              isViewOrthographic ( AcDb::OrthographicView& view ) const;
    Acad::ErrorStatus setViewDirection   ( AcDb::OrthographicView view );
};

class AcDbViewTableRecord: public  AcDbAbstractViewTableRecord
{
public:
    ACDB_DECLARE_MEMBERS(AcDbViewTableRecord);

    AcDbViewTableRecord();
    virtual ~AcDbViewTableRecord();

    typedef AcDbViewTable TableType;

    Acad::ErrorStatus setParametersFromViewport(AcDbObjectId objId);

    bool isPaperspaceView() const;
    void setIsPaperspaceView(bool pspace);
    
    bool    isUcsAssociatedToView   () const;
    Acad::ErrorStatus disassociateUcsFromView ();

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;

    Acad::ErrorStatus getCategoryName(char *& categoryName) const;
    Acad::ErrorStatus setCategoryName(const char * categoryName);

    Acad::ErrorStatus getLayerState(char*& layerStateName) const;
    Acad::ErrorStatus setLayerState(const char *layerStateName);
 
    Acad::ErrorStatus getLayout (AcDbObjectId& layoutId) const;
    Acad::ErrorStatus setLayout(AcDbObjectId layoutId);

    bool              isViewAssociatedToViewport () const;
    Acad::ErrorStatus setViewAssociatedToViewport (bool bVPflag);

#ifdef _WINDOWS_
    Acad::ErrorStatus getThumbnail (BITMAPINFO*& thumbnail) const;
    Acad::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);
#endif

};

class AcDbUCSTableRecord: public  AcDbSymbolTableRecord
{
public:
    ACDB_DECLARE_MEMBERS(AcDbUCSTableRecord);

    AcDbUCSTableRecord();
    virtual ~AcDbUCSTableRecord();

    typedef AcDbUCSTable TableType;

    AcGePoint3d  origin() const;
    void         setOrigin(const AcGePoint3d& newOrigin);

    AcGeVector3d xAxis() const;
    void         setXAxis(const AcGeVector3d& xAxis);

    AcGeVector3d yAxis() const;
    void         setYAxis(const AcGeVector3d& yAxis);

    AcGePoint3d       ucsBaseOrigin    ( AcDb::OrthographicView view ) const;
    Acad::ErrorStatus setUcsBaseOrigin ( const AcGePoint3d& origin,
                                         AcDb::OrthographicView view );
    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class AcDbViewportTableRecord: public  AcDbAbstractViewTableRecord
{
public:
    ACDB_DECLARE_MEMBERS(AcDbViewportTableRecord);

    AcDbViewportTableRecord();
    virtual ~AcDbViewportTableRecord();

    typedef AcDbViewportTable TableType;

    AcGePoint2d    lowerLeftCorner() const;
    void           setLowerLeftCorner(const AcGePoint2d& pt);

    AcGePoint2d    upperRightCorner() const;
    void           setUpperRightCorner(const AcGePoint2d& pt);

    bool           ucsFollowMode() const;
    void           setUcsFollowMode(bool enabled);

    Adesk::UInt16  circleSides() const;
    void           setCircleSides(Adesk::UInt16 circleSides);

    bool           fastZoomsEnabled() const { return true; }
    void           setFastZoomsEnabled(bool enabled) { }

    bool           iconEnabled() const;
    void           setIconEnabled(bool enabled);

    bool           iconAtOrigin() const;
    void           setIconAtOrigin(bool atOrigin);

    bool           gridEnabled() const;
    void           setGridEnabled(bool enabled);

    AcGePoint2d    gridIncrements() const;
    void           setGridIncrements(const AcGePoint2d& base);

    bool           snapEnabled() const;
    void           setSnapEnabled(bool enabled);

    bool           isometricSnapEnabled() const;
    void           setIsometricSnapEnabled(bool enabled);

    Adesk::Int16   snapPair() const;
    void           setSnapPair(Adesk::Int16 pairType);

    double         snapAngle() const;
    void           setSnapAngle(double angle);

    AcGePoint2d    snapBase() const;
    void           setSnapBase(const AcGePoint2d& base);

    AcGePoint2d    snapIncrements() const;
    void           setSnapIncrements(const AcGePoint2d& base);

    void           setGsView(AcGsView* pView);
    AcGsView*      gsView() const;

    bool           isUcsSavedWithViewport () const;
    void           setUcsPerViewport ( bool ucsvp );


    // Drawable API
    //
    AcGiDrawable*  drawable();
    Adesk::UInt32  setAttributes(AcGiDrawableTraits* pTraits);
    Adesk::Boolean worldDraw(AcGiWorldDraw* pWd);     
    void           setGsNode(AcGsNode* pNode);
    AcGsNode*      gsNode() const;

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class AcDbRegAppTableRecord: public  AcDbSymbolTableRecord
{
public:
    ACDB_DECLARE_MEMBERS(AcDbRegAppTableRecord);

    AcDbRegAppTableRecord();
    virtual ~AcDbRegAppTableRecord();

    typedef AcDbRegAppTable TableType;

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class AcDbDimStyleTableRecord: public  AcDbSymbolTableRecord
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDimStyleTableRecord);

    AcDbDimStyleTableRecord();
    virtual ~AcDbDimStyleTableRecord();

    typedef AcDbDimStyleTable TableType;

    // Dimension variable api:
    //
    #undef DBDIMVAR_H         // force the file to get read again
    #include "dbdimvar.h"


    AcDbObjectId      arrowId(AcDb::DimArrowFlags whichArrow) const;


    // DEPRECATED METHODS!
    // These are supported but will be removed in future releases:
    //
    Acad::ErrorStatus getDimpost(char*& pOutput) const;
    Acad::ErrorStatus getDimapost(char*& pOutput) const;
    Acad::ErrorStatus getDimblk(char*& pOutput) const;
    Acad::ErrorStatus getDimblk1(char*& pOutput) const;
    Acad::ErrorStatus getDimblk2(char*& pOutput) const;

    int dimfit() const;
    int dimunit() const;

    Acad::ErrorStatus setDimfit(int fit);
    Acad::ErrorStatus setDimunit(int unit);
    //
    // end DEPRECATED METHODS!

    virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;
    bool isModifiedForRecompute() const;    
};

#pragma pack(pop)

#endif
