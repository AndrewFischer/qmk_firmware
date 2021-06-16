/* Copyright 2021 AndrewFischer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "autopilot.h"

#if defined(OLED_DRIVER_ENABLE)
__attribute__((weak))
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;  // AutoPilot has a horizontal display. 
}
__attribute__((weak)) 
void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("AutoPilot"), false);
}

#endif