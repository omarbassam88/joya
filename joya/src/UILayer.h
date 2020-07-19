#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "Layer.h"
#include "Events/MouseEvent.h"

namespace JY
{
    class UILayer : public Layer
    {
    private:
        /* data */
    public:
        UILayer();
        ~UILayer() = default;
        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnUpdate() override;
        virtual void OnEvent(Event &e) override;

        bool OnMouseButtonPressed(MouseButtonPressed &e);
        bool OnMouseButtonReleased(MouseButtonReleased &e);
    };

} // namespace JY

#endif // __UILAYER_H__