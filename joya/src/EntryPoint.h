
extern JY::App* JY::CreateApp();

int main(int argc, char const *argv[])
{
    auto app = JY::CreateApp();
    app->Run();
    delete app;

}
