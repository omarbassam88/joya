#include "LayerStack.h"

namespace JY
{
    LayerStack::~LayerStack()
    {
        for (Layer *layer : m_LayerStack)
        {
            layer->OnDetach();
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer *layer)
    {
        m_LayerStack.emplace(begin() + m_LayerInsertIndex, layer);
        m_LayerInsertIndex++;
    }

    void LayerStack::PushOverlay(Layer *overlay)
    {
        m_LayerStack.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer)
    {
        auto it = std::find(m_LayerStack.begin(), m_LayerStack.begin() + m_LayerInsertIndex, layer);
        if (it != m_LayerStack.begin() + m_LayerInsertIndex)
        {
            layer->OnDetach();
            m_LayerStack.erase(it);
            m_LayerInsertIndex--;
        }
    }

    void LayerStack::PopOverlay(Layer *overlay)
    {
        auto it = std::find(m_LayerStack.begin() + m_LayerInsertIndex, m_LayerStack.end(), overlay);
        if (it != m_LayerStack.end())
        {
            overlay->OnDetach();
            m_LayerStack.erase(it);
        }
    }

} // namespace JY
