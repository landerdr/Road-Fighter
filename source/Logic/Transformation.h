//
// Created by lander on 12/22/18.
//

#ifndef ROAD_FIGHTER_TRANSFORMATION_H
#define ROAD_FIGHTER_TRANSFORMATION_H

#include <memory>

namespace roadfighter {
    class Transformation {
    public:
        static std::shared_ptr<Transformation> Instance();

        void setSize(unsigned int ix, unsigned int iy);

        int transX(double fx);
        int transY(double fy);

        float getScaleX();
        float getScaleY();


    private:
        static std::shared_ptr<Transformation> m_pTransformation;

        unsigned int x;
        unsigned int y;
    };
}


#endif //ROAD_FIGHTER_TRANSFORMATION_H
