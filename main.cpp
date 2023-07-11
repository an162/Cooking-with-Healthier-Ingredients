#include<iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "Rational.h"
#include <limits>
using namespace std;
struct HealthConcerns {
    bool isSuitableForHighCholesterol;
    bool isSuitableForHighBloodPressure;
    bool isSuitableForWeightLoss;
    bool isGlutenFree;
    // Add more health-related fields specific to the alternative
};

struct SubstitutionOption {
    std::string alternative;
    HealthConcerns healthConcerns;
    int conversionUnitNumerator;
    int conversionUnitDenumerator;
    //string additionalInfo;
};

struct SubstitutionOptions {
    std::vector<SubstitutionOption> options;
};

void insertSubstitution( std::unordered_map<std::string, SubstitutionOptions>& ingredientSubstitutions) {
   // Insert ingredient substitutions with options and health-related information
    SubstitutionOptions sugarSubs;
    sugarSubs.options = {
        {"honey", {true, true, true, false /* Health concerns for honey */},1,2/*,"Keep in mind that honey has a distinct flavor that can impact the taste of the final dish."*/},
        {"molasses", {false, false, false, false /* Health concerns for molasses */},1,1/*,"Molasses has a strong, rich flavor that can add depth and richness to recipes, especially in baking and savory dishes."*/},
         {"agave nectar",{false, false, false, false},1,4/*,"Agave nectar is sweeter than sugar, so you'll need less quantity. It also has a milder flavor compared to honey or molasses."*/}
    };
      ingredientSubstitutions["sugar"] = sugarSubs;
    SubstitutionOptions milkSubs;
    milkSubs.options = {
        {"almond milk", {true, true, true, false /* Health concerns for almond milk */},1,1/*,"It's important to note that almond milk may have a slightly different taste and texture compared to dairy milk.. It's recommended to choose unsweetened almond milk for a more neutral flavor that closely resembles regular milk."*/},
        {"oat milk", {true, true, true, false /* Health concerns for oat milk */},1,1/*,"Oat milk has a creamy texture and mild flavor that works well as a dairy milk alternative."*/},
        {"coconut milk", {false, false, false, false /* Health concerns for coconut milk */},3,4/*,"Coconut milk has a richer and more pronounced flavor compared to dairy milk. The substitution ratio can vary based on the desired coconut flavor in the recipe."*/},
        {"evaporated milk and water",{false, false, true, false},1,2/*,"Keep in mind that evaporated milk has a richer and creamier texture compared to regular milk, so the final result may have a slightly different taste and mouthfeel. Adjustments may be necessary based on personal preference and the specific recipe being prepared."*/},
        {"soy milk",{true, false, true, false},1,1/*, "Soy milk is a popular dairy milk alternative with a mild, creamy flavor that works well in many recipes.Remember to choose unsweetened soy milk for a more neutral flavor that closely resembles regular milk."*/}
    };
       ingredientSubstitutions["milk"] = milkSubs;
  SubstitutionOptions sourCreamSubs;
    sourCreamSubs.options = {
        {"yogurt (unsweetened, low-fat)", {true, true, true, false /* Health concerns for yogurt */},1,1},
        {"silken tofu", {true, true, true, false /* Health concerns for silken tofu */},1,1}
    };
    ingredientSubstitutions["sour cream"] = sourCreamSubs;

   SubstitutionOptions lemonJuiceSubs;
    lemonJuiceSubs.options = {
        {"vinegar", {false, false, true, false /* Health concerns for vinegar */},1,2}
    };
    ingredientSubstitutions["lemon juice"] = lemonJuiceSubs;

    SubstitutionOptions flourSubs;
    flourSubs.options = {
        {"whole wheat flour", {true, true, true, false /* Health concerns for whole wheat flour */},1,1},
        {"rice flour",{false, false, false, true},1,1}
    };
    ingredientSubstitutions["flour"] = flourSubs;

    SubstitutionOptions butterSubs;
    butterSubs.options = {
        {"olive oil", {true, true, true, false /* Health concerns for olive oil */},3,4},
        {"margarine",{false, false, false, false},1,1},
        {"yogurt",{true, true, true, false},1,1},
        {"coconut oil", {false, false, false, false /* Health concerns for coconut oil */},3,4}
    };
    ingredientSubstitutions["butter"] = butterSubs;

    SubstitutionOptions mayonnaiseSubs;
    mayonnaiseSubs.options = {
        {"cottage cheese",{true, true, true, false},1,1},
        {"Greek yogurt without added sugars", {true, true, true, false /* Health concerns for Greek yogurt */},7,8}
    };
    ingredientSubstitutions["mayonnaise"] = mayonnaiseSubs;

    SubstitutionOptions eggSubs;
    eggSubs.options = {
        {"egg whites", {true, true, true, false /* Health concerns for egg whites */},2,1}
    };
    ingredientSubstitutions["egg"] = eggSubs;

    SubstitutionOptions breadSubs;
    breadSubs.options = {
        {"whole-grain bread",{true, true, true, false},1,1},
        {"gluten-free bread", {false, false, true, true /* Health concerns for gluten-free bread */},1,1}
    };
    ingredientSubstitutions["white bread"] = breadSubs;

        SubstitutionOptions oilSubs;
    oilSubs.options = {
        {"unsweetened applesauce", {true, true, true, false /* Health concerns for gluten-free bread */},1,1}
    };
    ingredientSubstitutions["white bread"] = oilSubs;
}
void warnings(){
    cout<<"WARNINGS:"<<endl;
    cout<<"please dont use the alternatives carlesly unless you are sure about what you are "
    <<"doing especially cake recipes or sophisticated ones  (do not hurt the food) "
    <<endl
    <<"Always consult your physician before making significant changes to your diet"
    <<endl
    <<endl;
}

void IsHealthConcern(HealthConcerns& userHealthConcerns){

    std::cout << "Please specify your health concerns:" << std::endl;
            std::string input="";
    do {

        std::cout << "High cholesterol (1 for yes, 0 for no): ";
        std::cin >> input;

        if (input != "0" && input != "1") {
            std::cout << "Invalid input. Please enter 1 for yes or 0 for no." << std::endl;
        } else {
            userHealthConcerns.isSuitableForHighCholesterol = std::stoi(input);
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (input != "0" && input != "1");

    input="";
 do {

        std::cout << "High blood pressure (1 for yes, 0 for no): ";
        std::cin >> input;

        if (input != "0" && input != "1") {
            std::cout << "Invalid input. Please enter 1 for yes or 0 for no." << std::endl;
        } else {
            userHealthConcerns.isSuitableForHighBloodPressure = std::stoi(input);
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (input != "0" && input != "1");

       input="";
   do {

        std::cout << "Weight loss (1 for yes, 0 for no): ";
        std::cin >> input;

        if (input != "0" && input != "1") {
            std::cout << "Invalid input. Please enter 1 for yes or 0 for no." << std::endl;
        } else {
            userHealthConcerns.isSuitableForWeightLoss = std::stoi(input);
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (input != "0" && input != "1");

       input="";
    do {

        std::cout << "Gluten allergy (1 for yes, 0 for no): ";
        std::cin >> input;

        if (input != "0" && input != "1") {
            std::cout << "Invalid input. Please enter 1 for yes or 0 for no." << std::endl;
        } else {
            userHealthConcerns.isGlutenFree = std::stoi(input);
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (input != "0" && input != "1");

}

void searching(HealthConcerns& userHealthConcerns, std::unordered_map<std::string, SubstitutionOptions>& ingredientSubstitutions, const std::string& ingredient,
                              std::vector<SubstitutionOption>& suitableOptions){


    if (ingredientSubstitutions.count(ingredient) > 0) {
        const SubstitutionOptions& options = ingredientSubstitutions[ingredient];

        for (const SubstitutionOption& option : options.options) {
bool isOptionSuitable = true; // Assume the option is suitable initially

if (userHealthConcerns.isGlutenFree && !option.healthConcerns.isGlutenFree) {
    isOptionSuitable = false;
}

if (userHealthConcerns.isSuitableForHighCholesterol && !option.healthConcerns.isSuitableForHighCholesterol) {
    isOptionSuitable = false;
}

if (userHealthConcerns.isSuitableForHighBloodPressure && !option.healthConcerns.isSuitableForHighBloodPressure) {
    isOptionSuitable = false;
}

if (userHealthConcerns.isSuitableForWeightLoss && !option.healthConcerns.isSuitableForWeightLoss) {
    isOptionSuitable = false;
}

if (isOptionSuitable) {
    suitableOptions.push_back(option);
    }
 }
   }



}

int main(){
    HealthConcerns userHealthConcerns;
    string measurment, ingredient;
    Rational quantity(0,1);
      std::vector<SubstitutionOption> suitableOptions;
    cout<<"Enter a recipe, get a healthier alternatives"
    <<endl<<endl;
    warnings();
    IsHealthConcern(userHealthConcerns);

    cout<<"Enter quantity (as a rational number) , measurement tool then the ingredient"<<endl;
    cout<<"eg: 1/2 cup sugar"<<endl;
    cout<<"quantity: ";cin>>quantity;
    std::cin.ignore(); // Ignore the newline character
    cout<<"measurment tool: ";getline(cin, measurment);
    cout<<"ingredient: "; getline(cin, ingredient);

    // Call the searching() function to get suitable alternatives based on user's health concerns
    std::unordered_map<std::string, SubstitutionOptions> ingredientSubstitutions;
    insertSubstitution(ingredientSubstitutions);
    searching(userHealthConcerns, ingredientSubstitutions, ingredient,suitableOptions);

 if (!suitableOptions.empty() ) {
    std::cout << "Substitution options for " << quantity << " " << measurment << " " << ingredient << ":" << std::endl;
   for (size_t i = 0; i < suitableOptions.size(); ++i) {
    Rational convergentRatio(suitableOptions[i].conversionUnitNumerator, suitableOptions[i].conversionUnitDenumerator);
    std::cout << "--> " << quantity * convergentRatio << " " << measurment << " " << suitableOptions[i].alternative << std::endl;

}

    } else {
        std::cout << "No suitable substitutions found for " << ingredient << " based on your health concerns." << std::endl;
    }


return 0;
}
