//
// Created by lander on 12/22/18.
//

#ifndef ROAD_FIGHTER_TRANSFORMATION_H
#define ROAD_FIGHTER_TRANSFORMATION_H

#include <memory>

namespace roadfighter {
class Transformation
{
public:
        static std::shared_ptr<Transformation> Instance();

        void setSize(unsigned int ix, unsigned int iy);

        /**
         * Transforms virtual x position to absolute x position on screen
         * @param fx
         * @return
         */
        int transX(double fx);
        /**
         * Transforms virtual y position to absolute y position on screen
         * @param fy
         * @return
         */
        int transY(double fy);
        /**
         * Calculates the x scale
         * @return
         */
        float getScaleX();
        /**
         * Calculates the y scale
         * @return
         */
        float getScaleY();

private:
        static std::shared_ptr<Transformation> m_pTransformation;

        // Size from screen
        unsigned int x;
        unsigned int y;
};
} // namespace roadfighter

#endif // ROAD_FIGHTER_TRANSFORMATION_H
