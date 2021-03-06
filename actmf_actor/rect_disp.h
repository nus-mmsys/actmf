/*
 * Actor Multimedia Framework (actmf)
 * Copyright (C) 2016  Arash Shafiei
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef ACTMF_RECT_DISP_H
#define ACTMF_RECT_DISP_H

#include "actmf_interface/abstract_service.h"

namespace actmf {
  
  using rect_disp_actor = 
  caf::typed_actor<caf::replies_to<std::string, std::vector<opencv_rect>>::with<int>>;
  
  class rect_disp_bhvr : public
  caf::composed_behavior<caf::composable_behavior<rect_disp_actor>, abstract_service_bhvr> {
  public:
    caf::result<int> operator()(caf::param<std::string>, caf::param<std::vector<opencv_rect>>) override; 
  };
  
  class rect_disp_factory : abstract_service_factory
  {
  protected:
   virtual caf::actor spawn();
  };
 
}

#endif // ACTMF_RECT_DISP_H