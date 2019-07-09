#ifndef BS_CALL_H
#define BS_CALL_H

class BSCall
{
public:
    BSCall(double r_, double d_,
            double T_, double Spot_,
            double Strike_);

    double operator()(double Vol) const;

private:
    double r;
    double d;
    double T;
    double Spot;
    double Strike;    
};

#endif