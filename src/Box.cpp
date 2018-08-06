#include "Box.h"

uint Box::_maxParts = 9;

SDL_Rect Box::_croppedParts[9] = {
    {0, 0, 8, 8},   // top left
    {16, 0, 8, 8},  // top right
    {0, 16, 8, 8},  // bottom right
    {16, 16, 8, 8}, // bottom left
    {0, 8, 8, 8},   // left
    {8, 0, 8, 8},   // top
    {16, 8, 8, 8},  // right
    {8, 16, 8, 8},  // bottom
    {8, 8, 8, 8}    // center
};

int Box::_switchSignX[4] = { -1, 1, -1, 1};
int Box::_switchSignY[4] = { -1, -1, 1, 1};
int Box::_switchSignW[4] = { 0, 1, 0, 1};
int Box::_switchSignH[4] = { 1, 0, 1, 0};

#define QUICK_SPRITE_SETTER(index, x, y, w, h) \
    _sprites[index]->crop(_croppedParts[index]); \
    _sprites[index]->setX(x); \
    _sprites[index]->setY(y); \
    _sprites[index]->setW(w); \
    _sprites[index]->setH(h);

Box::Box(int x, int y, int w, int h)
    : Object(x, y, w, h)
    , _sprites(new Sprite*[_maxParts])
{
    LOG_DEBUG("Create new Box " + ptr2Str(this));

    if (w < 100) w = 100;
    if (h < 32) h = 32;

    int dW = 0;
    int dH = 0;
    int dX = x - (w / 2);
    int dY = y - (h / 2);

    // FIXME: optimizeeeeeeeeeeeeeeeeeee this codeeeeeeeeeeeeeeeeeeeee

    for (int i = 0; i < _maxParts; ++i)
        _sprites[i] = new Sprite(PATH_BOX_PNG, 0, 0, 8, 8);

    // Crop for center part
    QUICK_SPRITE_SETTER(8,
        dX + 8,
        dY + 8,
        w - 24,
        h - 24);

    for (int i = 0; i < 4; ++i) {
        dW = _switchSignX[i] * w / 2;
        dH = _switchSignY[i] * h / 2;

        QUICK_SPRITE_SETTER(i,
            x + dW - _croppedParts[i].x,
            y + dH - _croppedParts[i].y,
            _croppedParts[i].w,
            _croppedParts[i].h);
    }

    QUICK_SPRITE_SETTER(4,
        dX,
        dY + 8,
        8,
        h - 24);

    QUICK_SPRITE_SETTER(5,
        dX + 8,
        dY,
        w - 24,
        8);

    QUICK_SPRITE_SETTER(6,
        dX + w - 16,
        dY + 8,
        8,
        h - 24);

    QUICK_SPRITE_SETTER(7,
        dX + 8,
        dY + h - 16,
        w - 24,
        8);
}

Box::Box()
    : Box(0, 0, 0, 0)
{
}

Box::~Box() {
    LOG_DEBUG("Delete Box " + ptr2Str(this));

    for (int i = 0; i < 9; ++i)
        delete _sprites[i];

    delete[] _sprites;
}

void Box::_draw() {
    for (int i = 0; i < 9; ++i)
        _sprites[i]->draw();
}

void Box::setColor(SDL_Color color) {
    for (int i = 0; i < 9; ++i)
        _sprites[i]->setColor(color);
}

void Box::update() {}

void Box::onMousePressed() {}

void Box::onMouseHovered() {
    Object::setColor("#99FF00");
}

void Box::onMouseLeft() {
    Object::setColor("#FFFFFF");
}

void Box::onMouseReleased() {}

void Box::onKeyPressed(SDL_Event* event) {}

void Box::onKeyReleased(SDL_Event* event) {}
