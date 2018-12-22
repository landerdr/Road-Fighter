//
// Created by lander on 12/22/18.
//

#ifndef ROAD_FIGHTER_TRANSFORMATION_H
#define ROAD_FIGHTER_TRANSFORMATION_H


class Transformation {
protected:
    Transformation();
public:
    virtual ~Transformation();
    static Transformation* Instance();

private:
    static Transformation* m_pTransformation;
};


#endif //ROAD_FIGHTER_TRANSFORMATION_H
