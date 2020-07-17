#ifndef __LAYERSTACK_H__
#define __LAYERSTACK_H__

#include "Layer.h"
#include <vector>
#include <algorithm>
namespace JY
{
    class LayerStack
    {
    private:
        std::vector<Layer *> m_LayerStack;
        unsigned int m_LayerInsertIndex;

    public:
        LayerStack() = default;
        ~LayerStack();
        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
        void PopLayer(Layer *layer);
        void PopOverlay(Layer *overlay);

        std::vector<Layer *>::iterator begin() { return m_LayerStack.begin(); }
        std::vector<Layer *>::iterator end() { return m_LayerStack.end(); }
    };

} // namespace JY

#endif // __LAYERSTACK_H__