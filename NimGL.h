#pragma once

#include "NWindow.h"

// Core functions
void NInit();
void NEnd();

// Helper functions
glm::vec4 NColor(uint32_t _32bpp);
glm::vec4 NColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
glm::vec4 NColor(float r, float g, float b, float a);
