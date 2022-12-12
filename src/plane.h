#pragma once

class plane {
    public:
        plane();
        plane(int s, int d);
        plane(int s, int d, double w);

        int getSourceId();       
        int getDestId();         
        double getWeight();
       
        void setWeight(double w);
        void setSource(double s);
        void setDestination(double d); 
        bool operator<(const plane& other) const;
        bool operator==(plane& other) const;
    
    private:
        int sourceAP;
        int destinationAP;
        double weight;
};