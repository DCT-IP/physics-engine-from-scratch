#pragma once

class Body;

class ForceGenerator { 
    public:
        virtual ~ForceGenerator() = default;
        virtual void apply(Body& body) = 0;
};
