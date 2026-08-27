#ifndef BULLET_H
#define BULLET_H


class Bullet {

    private:
        int bulletx;
        int bullety;
        Texture2D bulletimage;
        

    public:
        // Constructor
        Bullet(int x, int y);
    
        
    
        // Member functions
        int getx() const;
        int gety() const;
        
        Texture2D getimage() const;
        
        void sety(int y);
        
};

#endif