#pragma once
#include <iostream> 
#include "../external/json/json.hpp"
#include <vector>

//Create a Scene Class for the game. 
// This class will house how the Scenes will look like

 class Scene {

//We can start defining the object of our class with
// name and description. This will be the bare bones of the project
    public struct Scene_Composition{ 
        std::int ID;           
        std::string name;       
        std::string description   
       
       
    }
    // a method/function that we will define later
    // choices will be used to handle what happens after a scene 
     display_choices();
     process_choice();
 } 


// Create a choice Struct 

struct Choice {
    std::int ID;
    std::char text;
    std::int next_scene_id;

}

// Define a function to create a new choice
Choice create_choice(int ID, const char text , int next_scene_id)

// Define a function to process player choice
int process_choice(Choice choices, int num_choices);

// Define a function to display available choices
void display_choices(Choice choices, int num_choices);






#endif