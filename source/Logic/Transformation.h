//
// Created by lander on 12/22/18.
//

#ifndef ROAD_FIGHTER_TRANSFORMATION_H
#define ROAD_FIGHTER_TRANSFORMATION_H

#include <memory>

class Transformation {
protected:
    Transformation();
public:
    virtual ~Transformation();
    static std::shared_ptr<Transformation> Instance();

    void setSize(unsigned int ix, unsigned int iy);

    int transX(float fx);
    int transY(float fy);

private:
    static std::shared_ptr<Transformation> m_pTransformation;

    unsigned int x;
    unsigned int y;
};


#endif //ROAD_FIGHTER_TRANSFORMATION_H
