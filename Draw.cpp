void DrawTree(long leaf)
{
	POLYGON *CurrentPoly;
	int i;
	long PVSOFFSET=LeafArray[leaf].PVSIndex;
	BYTE *PVSPointer=PVSData;
	PVSPointer+=PVSOFFSET;
	long currentleaf=0;
	while (currentleaf<NumberOfLeafs)
	{
		if(*PVSPointer!=0)
		{
			for (i=0;i<8;i++)
			{
				BYTE mask=1<<i;
				BYTE pvs=*PVSPointer;
				if (pvs&mask)
				{
					// Render the Polygons in leaf
				} // end for if pvsdata
				currentleaf++;
			}//end for i
			PVSPointer++;
		}
		else
		{ // we have hit a zero so read run length
			PVSPointer++;
			BYTE RunLength=*PVSPointer;
			PVSPointer++;
			currentleaf+=RunLength*8;
		}
	}
}