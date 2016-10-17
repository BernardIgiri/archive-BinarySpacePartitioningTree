#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
#include <winuser.h> 
#include <winbase.h>
#include <stdlib.h>
#include "BSPTreeGlobals.h"

void ReserveInitialMemoryForArrays()
{
	NodeArray= (NODE *)malloc(MAXNUMBEROFNODES*sizeof(NODE));
	PolygonArray=(POLYGON *)malloc(MAXNUMBEROFPOLYGONS*sizeof(POLYGON));
	PlaneArray=(PLANE *)malloc(MAXNUMBEROFPLANES*sizeof(PLANE));
	LeafArray=(LEAF *)malloc(MAXNUMBEROFLEAFS*sizeof(LEAF));
	PortalArray=(PORTAL **)malloc(MAXNUMBEROFPORTALS*sizeof(PORTAL *));

	ZeroMemory(NodeArray, sizeof(NODE)*MAXNUMBEROFNODES);
	ZeroMemory(LeafArray, sizeof(LEAF)*MAXNUMBEROFLEAFS);
	ZeroMemory(PlaneArray, sizeof(PLANE)*MAXNUMBEROFPLANES);
	ZeroMemory(PolygonArray, sizeof(POLYGON)*MAXNUMBEROFPOLYGONS);
	ZeroMemory(PortalArray, sizeof(PORTAL*)*MAXNUMBEROFPORTALS);
}