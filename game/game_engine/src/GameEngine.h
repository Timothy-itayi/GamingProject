#pragma once
#include <iostream> 
#include "../external/json/json.hpp"
#include <vector>

//Create a Scene Class for the game. 
// This class will house how the Scenes will look like

 class Scene {

//We can start defining the object of our class with
// name and description. This will be the bare bones of the project
private:
    
        int scene_id;           
        std::string title;       
        std::string description;  
        std::vector<std::string> choices; 
public: 
    // Constructor
    Scene(int id, std::string t, std::string desc)
    : scene_id(id), title(t), description(desc) {}    
       
    
    
 
 }; 

// Create function to create new scene 
Scene create_Scene(int scene_id, const string description);

// Function to load a scene from a file 
Scene load_scene_from_Json(const filename);


// Function to transition to a new Scene
Scene transition_to_scene(int next_scene_id);

//Function to add a choice to a scene 
int add_choice_to_scene(Scene scene, const string, int next_scene_id );





// Create a choice Class to place in the heap. 

class  Choice {
    std::int choice_id;
    std::string text;
    std::int next_scene_id;

}

// Define a function to create a new choice
Choice create_choice(int choice_id, const string text , int next_scene_id)

// Define a function to process player choice
int process_choice(Choice choices, int num_choices);

// Define a function to display available choices
void display_choices(Choice choices, int num_choices);






#endif