#include "stdafx.h"

//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
//Rectangle Area
//Assume that the total area is never beyond the maximum possible value of int.

namespace Solution2
{
    namespace RectangleArea
    {
     
		int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
		{
			int result = (C - A) * (D - B) + (G - E) * (H - F);
			if (C < E || B > H || G < A || F > D) { return result; }
			return result - (min(D, H) - max(B, F)) * (min(C, G) - max(A, E));
		}
     
        void Main()
        {
         
        }
    }
}
