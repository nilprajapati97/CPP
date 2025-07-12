#include <iostream>
#include <vector>
#include <memory>
#include <vector>
using namespace std;

class event_t {

private:
    vector<function<void()>> handlers;
	

public:
    void subscribe(function<void()> handlers) 
	{
        handlers.push_back(handler);
    }
 
    void trigger() 
	{
        for (auto & handler : handlers) {
            handler();
        }
    }
 

};
 
class button_t {
public:
    event_t on_click;
 
    void click()
	{
        cout << "Button clicked\n";
        on_click.trigger();
   
};
 
class app_t {
private:
    string _name;

public:
      app_t(const string  &obj) 
	  {
	     obj._name = n [strlen(obj._name )] +1;
	     //  copy value into variable _name using strcp
	  }
	  
    void run()
	{
        auto button = make_unique<button_t>();
 
        button->on_click.subscribe([=]() 
		{
            cout << "Button was clicked (App " << _name << ")\n";
            return true;
        });
        
		button->on_click.subscribe([]() {
            cout << "Button was clicked \n";
        });
 
        button->click();
    }
	
	~app_t() 
	  {
	    // code for deleteng  
		}
 

};
 
int main() {
    app_t app("MyApp");
    app.run();
}
 
 