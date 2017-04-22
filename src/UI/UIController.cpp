//
// Created by zakrent on 4/22/17.
//

#include "UIController.h"
#include "UIHealthElement.h"

namespace UI {


    UIController::UIController(Entity::Entity* Player) {
        UIElements.push_back(new UIHealthElement(Player));
    }

    void UIController::draw(SDL_Renderer *mainRenderer) {
        for(UIBaseElement* uiElement : UIElements){
            uiElement->draw(mainRenderer);
        }
    }
}