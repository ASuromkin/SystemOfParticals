#include "includes/engine.hpp"

int main(int argc,char* argv[]){

    auto engine = std::make_shared<Engine>();
    engine->Run();
    return 0;
}
