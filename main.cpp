#include "crow.h"
#include "json.h"

#include <sstream>


int main()
{

  crow::SimpleApp app;

  CROW_ROUTE(app , "/about")
  ([](){
    return "About Crow Exemplo C++ is power";
  });

  CROW_ROUTE(app, "/json")
  ([]{
    crow::json::wvalue x;
    x["message"] = "Hello, World!";
    return x;
  });

  CROW_ROUTE(app,"/hello/<int>")
  ([](int count){
      if (count > 100)
          return crow::response(400);
      std::ostringstream os;
      os << count << " bottles of beer!";
      return crow::response(os.str());
  });

  CROW_ROUTE(app, "/add_json")
    .methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x)
            return crow::response(400);
        int sum = x["a"].i()+x["b"].i();
        std::ostringstream os;
        os << sum;
        return crow::response{os.str()};
  });

  app.port(3000)
    .multithreaded()
    .run();
}
