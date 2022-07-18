#pragma once

class Feature {
public:
    bool pleaseDelete;
    Feature();
    virtual ~Feature();
    virtual void Render();
};