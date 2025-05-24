#include "stdafx.h"
#include "global.h"
#include "pbrush.h"
#include "imgtools.h"
#include "imgsuprt.h"

#ifdef _DEBUG
#undef THIS_FILE
static CHAR BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CTriangleTool, CClosedFormTool)

CTriangleTool::CTriangleTool()
{
    m_nCmdID = IDMB_TRIANGLETOOL;
}

void CTriangleTool::Render(CDC* pDC, CRect& rect, BOOL bDraw, BOOL bCommit, BOOL bCtrlDown)
{
    int sx, sy, ex, ey;
    HBRUSH hBr = NULL;
    HPEN hPen = NULL;
    HPEN hOldPen = NULL;
    HBRUSH hOldBr = NULL;
    CPoint pt1, pt2;
    HDC hDC = pDC->m_hDC;

    FixRect(&rect);

    pt1.x = rect.left;
    pt1.y = rect.top;
    pt2.x = rect.right;
    pt2.y = rect.bottom;

    StandardiseCoords(&pt1, &pt2);

    sx = pt1.x;
    sy = pt1.y;
    ex = pt2.x;
    ey = pt2.y;

    SetupPenBrush(hDC, bDraw, TRUE, bCtrlDown);

    // Create triangle points
    POINT points[3];
    points[0].x = (sx + ex) / 2;  // Top point (middle)
    points[0].y = sy;
    points[1].x = sx;             // Bottom left
    points[1].y = ey;
    points[2].x = ex;             // Bottom right
    points[2].y = ey;

    // Draw the triangle
    Polygon(hDC, points, 3);

    SetupPenBrush(hDC, bDraw, FALSE, bCtrlDown);

    // Update the rectangle to include the entire triangle
    rect.left = sx;
    rect.top = sy;
    rect.right = ex;
    rect.bottom = ey;
} 