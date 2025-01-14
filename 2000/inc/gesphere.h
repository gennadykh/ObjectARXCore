#ifndef AC_GESPHERE_H
#define AC_GESPHERE_H
//
// (C) Copyright 1993-1999 by Autodesk, Inc.
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
// Description:
//
// This file implements the class AcGeSphere, a representation for a
// sphere.  It is defined by its radius, and the center. Two vectors,
// northAxis and refAxis are used in the parameterization of
// the sphere.  northAxis identifies the north and the south poles
// of the sphere. refAxis serves as a reference for the parameters.
// It is a vector orthogonal to northAxis.
// Parameter u is the longitude, which for a closed sphere defaults
// to the range [-PI, PI).  Zero corresponds to the meridian that
// contains the refAxis of the sphere.
// Parameter v is the latitude, which for a closed sphere defaults
// to the range [-PI/2, PI/2].  The lower bound maps to the south
// pole, zero is on the equator, and the upperbound maps to the north
// pole.
// The sphere is periodic in u with a period of 2PI.
// [umin, umax] x [vmin, vmax] defines a four sided spherical patch
// bounded by two arcs that are meridians of longitude, and two arcs
// that are parallels of latitude.  Following constraints apply when
// defining a spherical patch.
// umin < umax and |umin - umax| <= 2PI.
// vmin < vmax and |vmin - vmax| <= PI.
//


#include "gegbl.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "geintrvl.h"
#include "gesurf.h"
#pragma pack (push, 8)

class AcGeCircArc3d;

class
#ifdef AC_GESPHERE_CPP
GE_DLLEXPORT
#else
GE_DLLIMPORT
#endif
AcGeSphere : public AcGeSurface
{
public:
    AcGeSphere();
    AcGeSphere(double radius, const AcGePoint3d& center);
    AcGeSphere(double radius, const AcGePoint3d& center,
               const AcGeVector3d& northAxis, const AcGeVector3d& refAxis,
               double startAngleU, double endAngleU,
               double startAngleV, double endAngleV);
    AcGeSphere(const AcGeSphere& sphere);

    // Geometric properties.
    //
    double         radius            () const;
    AcGePoint3d    center            () const;
    void           getAnglesInU      (double& start, double& end) const;
    void           getAnglesInV      (double& start, double& end) const;
    AcGeVector3d   northAxis         () const;
    AcGeVector3d   refAxis           () const;
    AcGePoint3d    northPole         () const;
    AcGePoint3d    southPole         () const;
    Adesk::Boolean isOuterNormal     () const;
    Adesk::Boolean isClosed       (const AcGeTol& tol = AcGeContext::gTol) const;

    AcGeSphere&    setRadius         (double);
    AcGeSphere&    setAnglesInU      (double start, double end);
    AcGeSphere&    setAnglesInV      (double start, double end);
    AcGeSphere&    set               (double radius, const AcGePoint3d& center);
    AcGeSphere&    set               (double radius, const AcGePoint3d& center,
                                      const AcGeVector3d& northAxis,
                                      const AcGeVector3d& refAxis,
                                      double startAngleU,
                                      double endAngleU,
                                      double startAngleV,
                                      double endAngleV);
    // Assignment operator.
    //
    AcGeSphere&    operator =     (const AcGeSphere& sphere);

    // Intersection with a linear entity
    //
    Adesk::Boolean intersectWith  (const AcGeLinearEnt3d&, int& intn,
                                   AcGePoint3d& p1, AcGePoint3d& p2,
                                   const AcGeTol& tol = AcGeContext::gTol) const;
};

#pragma pack (pop)
#endif
