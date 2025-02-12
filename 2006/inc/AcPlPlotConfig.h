#ifndef ACPLPLOTCONFIG_H
#define ACPLPLOTCONFIG_H
//
//  (C) Copyright 2003 by Autodesk, Inc.  All rights reserved.
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
//  DESCRIPTION:  Header for Document and Document Manager Classes.
//

#include "AcPl.h"

#include "AcArray.h"
#include "gepnt2d.h"
#include "geblok2d.h"
#include "dblayout.h"

class HT_Plot_Config;
class HT_Media_Size;
class HT_Media_Description;

class AcPlPlotConfig : public AcPlObject
{
    ACPL_DECLARE_MEMBERS(AcPlPlotConfig)

public:
    enum PlotToFileCapability {
        kNoPlotToFile       = 0,
        kPlotToFileAllowed  = 1,
        kMustPlotToFile     = 2
    };
        
public:
    ACPL_PORT virtual ~AcPlPlotConfig();

    ACPL_PORT virtual Acad::ErrorStatus copyFrom(const AcRxObject* pSrc);


    // returns the description field information - driver name
    // location, comment, port name, server name and tag line
    ACPL_PORT virtual void getDescriptionFields(char* &pDriverName,
                                                char* &pLocationName,
                                                char* &pComment,
                                                char* &pPortName,
                                                char* &pServerName,
                                                char* &pTagLine) const;

    // returns the current device name from the current plot config
    ACPL_PORT virtual const char* deviceName() const;

    // returns the full path name if the current plot config is of a pc3 file
    // or the UNC name if it is a system printer
    ACPL_PORT virtual const char* fullPath() const;

    // returns the maximum DPI supported by the device
    ACPL_PORT virtual unsigned int maxDeviceDPI() const;

    // returns the deviceType for the current plot config device
    ACPL_PORT virtual unsigned long deviceType() const;

    // returns the canonical media name list for the current device
    ACPL_PORT virtual void getCanonicalMediaNameList(AcArray<char*> &mediaList) const;

    // given a canonical media name, returns its local media name
    ACPL_PORT virtual void getLocalMediaName(const char* pCanonicalMediaName, 
                                             char* &pLocalMediaName) const;

    // returns the media bounds (page size and printable bounds) for the 
    // canonical media name passed in
    ACPL_PORT virtual void getMediaBounds(const char* pCanonicalMediaName,
                                          AcGePoint2d &pageSize, 
                                          AcGeBoundBlock2d &printableArea) const;

    // resets the current cached media name list
    ACPL_PORT virtual void refreshMediaNameList();

    // gets/sets the config's plot to file setting
    ACPL_PORT virtual bool isPlotToFile() const;
    ACPL_PORT virtual Acad::ErrorStatus setPlotToFile(bool bPlotToFile);

    // returns the device's default file extension (if any)
    // including the leading '.'
    ACPL_PORT virtual Acad::ErrorStatus getDefaultFileExtension(const char*& pDefaultExtension) const;

    // returns the device's plot-to-file capability
    ACPL_PORT virtual PlotToFileCapability plotToFileCapability() const;

    // saves the current configuration to the specified pc3 file
    // Note: This doesn't load the saved pc3 as current config.
    // Use the method getPlotConfig() and pass in saved pc3 file to 
    // get to the plot config
    ACPL_PORT virtual bool saveToPC3(const char* pPC3Name);

    // returns the current HT_Plot_Config object (for internal use only)
    ACPL_PORT virtual HT_Plot_Config* plotConfig() const;
    
    // internal use only
    ACPL_PORT virtual unsigned long isCustomPossible(double width, double height, 
                                  bool bIsDimensional, bool bIsSheet, int dpi, const
                                  char * pPC3Dir) const;
    
    // internal use only
    ACPL_PORT virtual bool matchMediaSize(double page_x, double page_y,
                                  double printable_w, double printable_h, 
                                  AcDbLayout::PlotPaperUnits units, 
                                  bool bIsSheet, int dpi, 
                                  const char * pTargetCanonicalName, 
                                  char *& pNearestSizeName, 
                                  char *& pLocalizedName,
                                  double & scaleFactor);

    // internal use only
    ACPL_PORT virtual Acad::ErrorStatus makeCustomMediaFromSizeDesc( 
        HT_Media_Size * pSize, HT_Media_Description * pDesc,
        bool bSameDriver, bool bSavePC3,
        const char * pSourceEntry, const char * pSourceName, 
        char *& pCanonicalSizeName, char *& pLocalizedSizeName, 
        char *& pPMPPath, char *& pPC3Path, int dpi, double & scaleFactor);

protected:
    friend class AcPlPlotConfigManagerImp;
    friend class AcPlPlotInfoImp;
    friend class AcPlPlotInfoValidatorImp;
    AcPlPlotConfig(HT_Plot_Config* pConfig, const char* pDevName, 
                   const char* pFullPath, unsigned long nDevType);

    AcPlPlotConfig(const AcPlPlotConfig* pOther);

private:
    AcPlPlotConfig();

};

#endif // ACPLPLOTCONFIG_H
