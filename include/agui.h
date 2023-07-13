/**
 * This is a simple helper library for handling some common responsive-ish ui stuff
 * 
 * Usage: In one file put this before including this file
 *  #define AGUI_IMPLEMENTATION
 */

#ifndef AGUI_H
#define AGUI_H

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif

#include "raylib.h"

Rectangle rectMargin(Rectangle box, int marginTop, int marginBot,
                     int marginLeft, int marginRight);

Rectangle rectMinSize(Rectangle box, Vector2 minSize, bool lockTop,
                      bool lockBot, bool lockLeft, bool lockRight);

Rectangle rectAnchor(Rectangle box, float startX, float endX, float startY,
                     float endY);

Rectangle rectStackVertical(Rectangle *box, float height, bool fromTop);
Rectangle rectStackHorizontal(Rectangle *box, float width, bool fromLeft);

Rectangle rectApplyScroll(Rectangle *box, Vector2 scroll);

#if defined(AGUI_IMPLEMENTATION)

Rectangle rectMargin(Rectangle box, int marginTop, int marginBot, int marginLeft, int marginRight) {
    Rectangle rect = {
        box.x + marginLeft,
        box.y + marginTop,
        box.width - marginLeft - marginRight,
        box.height - marginTop - marginBot
    };

    return rect;
}

Rectangle rectMinSize(Rectangle box, Vector2 minSize, bool lockTop,
                      bool lockBot, bool lockLeft, bool lockRight) {
    float deltaX = box.width > minSize.x ? 0 : minSize.x - box.width;
    float deltaY = box.height > minSize.y ? 0 : minSize.y - box.height;

    if (lockLeft && lockRight) deltaX /= 2; // Were gonna do half of the distance on each side
    if (lockTop && lockBot) deltaY /= 2;

    if (lockTop)  // Extend downwards
        box.height += deltaY;
    if (lockBot) {  // Extend Upwards
        box.height += deltaY;
        box.y -= deltaY;
    }
    if (lockLeft) {  // Extend to the right
        box.width += deltaX;
    }
    if (lockRight) {  // Extend to the left
        box.width += deltaX;
        box.x -= deltaX;
    }

    return box;
}

Rectangle rectAnchor(Rectangle box, float startX, float endX, float startY, float endY) {
    Rectangle rect = {
        box.x + box.width * startX,
        box.y + box.height * startY,
        box.width * (endX - startX),
        box.height * (endY - startY)
    };

    return rect;
}

Rectangle rectStackVertical(Rectangle *box, float height, bool fromTop) {
    Rectangle rect;
    if(fromTop) {
        rect = (Rectangle) { box->x, box->y, box->width, height };
        box->y += height;
        box->height -= height;
    } else {
        rect = (Rectangle) { box->x, box->y + box->height - height, box->width, height};
        box->height -= height;
    }
    return rect;
}

Rectangle rectStackHorizontal(Rectangle *box, float width, bool fromLeft) {
    Rectangle rect;
    if(fromLeft) {
        rect = (Rectangle) { box->x, box->y, width, box->height };
        box->x += width;
        box->width -= width;
    } else {
        rect = (Rectangle) { box->x + box->width - width, box->y, width, box->height};
        box->width -= width;
    }
    return rect;
}


Rectangle rectApplyScroll(Rectangle *box, Vector2 scroll) {
    return (Rectangle) { box->x + scroll.x, box->y + scroll.y, box->width, box->height};
}

#endif

#if defined(__cplusplus)
}
#endif

#endif