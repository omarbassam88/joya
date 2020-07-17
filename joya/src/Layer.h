#ifndef __LAYER_H__
#define __LAYER_H__

#include <string>

#include "Events/Event.h"
namespace JY
{
    class Layer
    {
    private:
        std::string m_Name;

    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();
        virtual void OnAttach();
        virtual void OnDetach();
        virtual void OnUpdate();
        virtual void OnEvent(Event &e);

        const std::string& GetName() { return m_Name; }
    };

} // namespace JY

#endif // __LAYER_H__