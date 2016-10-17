#ifndef __INCLUDED_BSPTREEGLOBALS_H__
#define __INCLUDED_BSPTREEGLOBALS_H__
#include "Polygons.h"
#include "BSPTreeTypes.h"

extern long MAXNUMBEROFNODES;
extern long MAXNUMBEROFPOLYGONS;
extern long MAXNUMBEROFPLANES;
extern long MAXNUMBEROFLEAFS;
extern long MAXNUMBEROFPORTALS;

extern POLYGON *PolygonArray;
extern NODE	*NodeArray;
extern LEAF	*LeafArray;
extern PLANE	*PlaneArray;
extern PORTAL	**PortalArray;
extern BYTE	*PVSData;

extern long NumberOfPolygons;
extern long NumberOfNodes;
extern long NumberOfLeafs;
extern long NumberOfPlanes;
extern long NumberOfPortals;

#endif//__INCLUDED_BSPTREEGLOBALS_H__