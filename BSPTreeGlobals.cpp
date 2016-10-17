#include "Polygon.h"
#include "BSPTreeTypes.h"

long MAXNUMBEROFNODES	 =100;
long MAXNUMBEROFPOLYGONS =100;
long MAXNUMBEROFPLANES	 =100;
long MAXNUMBEROFLEAFS	 =100;
long MAXNUMBEROFPORTALS	 =100;

POLYGON *PolygonArray;
NODE	*NodeArray;
LEAF	*LeafArray;
PLANE	*PlanArray;
PORTAL	**PortalArray;
BYTE	*PVSData;

long NumberOfPolygons=0;
long NumberOfNodes=0;
long NumberOfLeafs=0;
long NumberOfPlanes=0;
long NumberOfPortals=0;