#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

extern JY::App *JY::CreateApp();

int main(int argc, char const *argv[])
{
    auto app = JY::CreateApp();
    app->Run();
    delete app;
}

#endif // !ENTRYPOINT_H