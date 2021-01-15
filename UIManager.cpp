/*
 * UIManager.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: vishwajit
 */

#include <Common.h>
#include <GameManager.h>
#include <UIManager.h>

//todo save gametype in UIManager
void UIManager::statusUpdate(GameType gameType, std::string gotStatusText,
		std::string askHPTxt, std::string turnText,std::string moveInfoText,std::string rollInfoText,std::string rulesInfoText) {
	std::string gameTypeStr = "";
	if (_GOT) {
		gameTypeStr = "GoT";
	} else {
		gameTypeStr = "Regular";
	}
	SDL_Rect textRect;
	gameTypeTexture = renderer.LoadTextureFromString(
			("Game Type: " + gameTypeStr).c_str(), font, textColor);
	textRect = {965, 20, 256, 32}; // x,y,w,h
	SDL_RenderCopy(renderer.renderer, gameTypeTexture, NULL, &textRect);
	gameTypeTexture = renderer.LoadTextureFromString(
			turnText.c_str(), font, textColor);
	textRect = {965, 60, 256, 32}; // x,y,w,h
	SDL_RenderCopy(renderer.renderer, gameTypeTexture, NULL, &textRect);
	gameTypeTexture = renderer.LoadTextureFromString(
			moveInfoText.c_str(), font, textColor);
	textRect = {965, 100, 300, 32}; // x,y,w,h
	SDL_RenderCopy(renderer.renderer, gameTypeTexture, NULL, &textRect);

	if (askHPTxt =="") {
		gameTypeTexture = renderer.LoadTextureFromString(askHPTxt.c_str(), font,
				textColor);
		textRect.x = 965;
		textRect.y = 130;
		textRect.w = 300;
		textRect.h = 32;
		SDL_RenderCopy(renderer.renderer, gameTypeTexture, NULL, &textRect);
	}

	if (gameType == _GOT) {
		//SDL_Rect textRect;
		gameTypeTexture = renderer.LoadTextureFromString(gotStatusText.c_str(),
				font, textColor);
		textRect = {965, 160, 150, 32}; // x,y,w,h
		textRect = {965, 700, 150, 32}; // x,y,w,h
		SDL_RenderCopy(renderer.renderer, gameTypeTexture, NULL, &textRect);
	}
	std::string text = "Press P to pass";
	gameTypeTexture = renderer.LoadTextureFromString(text.c_str(), font,
			textColor);
	textRect = {965, 840, 300, 32}; // x,y,w,h
	SDL_RenderCopy(renderer.renderer, gameTypeTexture, NULL, &textRect);

	gameTypeTexture = renderer.LoadTextureFromString(
			rollInfoText.c_str(), font, textColor);
	textRect = {965, 800, 300, 32}; // x,y,w,h
	SDL_RenderCopy(renderer.renderer, gameTypeTexture, NULL, &textRect);

	gameTypeTexture = renderer.LoadTextureFromString(
			rulesInfoText.c_str(), font, textColor);
	textRect = {965, 930, 300, 32}; // x,y,w,h
	SDL_RenderCopy(renderer.renderer, gameTypeTexture, NULL, &textRect);
	SDL_RenderPresent(renderer.renderer);
}

GameType UIManager::onboarding() {
	renderNewTexture(_ONBOARDING);
	const SDL_MessageBoxButtonData buttons[] = { { 0, 0, "GoT" }, { 0, 1,
			"Traditional" }, };
	const SDL_MessageBoxData messageboxdata = { SDL_MESSAGEBOX_INFORMATION,
	NULL, "Welcome!!!", "Select game type", SDL_arraysize(buttons), buttons,
	NULL };

	int buttonid;
	if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
		cout<< "[GAME_MANAGER] error displaying message box" << endl;
		return _UNDEFINED;
	}
	if (buttonid == -1) {
		cout<< "[GAME_MANAGER] no selection made. asking again"
		<< endl;
		return _UNDEFINED;
	} else {
		cout << "[GAME_MANAGER] selection was " << buttonid << endl;
		if (buttonid == 1) {
			return _TRADITIONAL;
		} else {
			return _GOT;
		}
	}
}

void UIManager::init(const char *title, int xpos, int ypos, int width,
		int height, bool fullscreen) {
	std::string rulesStringTitle = "Welcome to Ludo - The GoT Edition";
	int isFullscreen = 0;
	if (fullscreen) {
		isFullscreen = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		int ttf = TTF_Init();
		if (ttf < 0) {
			while (1)
				;
		}
		window = SDL_CreateWindow(title, xpos, ypos, width, height,
				isFullscreen);
		if (!window) {
			cout<< "[GUI]: Unable to create window" << endl;
		}

		renderer.renderer = SDL_CreateRenderer(window, -1,
				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!renderer.renderer) {
			cout<< "[GUI]: Unable to create renderer" << endl;
			while (1)
			;

		} else {
			SDL_SetRenderDrawColor(renderer.renderer, 0, 0, 0, 0);
			gameTypeTexture = NULL;
			textColor = {255, 255, 255, 255};
			font = TTF_OpenFont("assets/fonts/Courier.TTF", 16);
			if (font == NULL) {
				cout << "[GUI]:  TTF input UI->font is null\n"
				<< endl;
				while (1)
				; //todo while(1) ????????
			}
		}
	}
}
void UIManager::drawBoard() {
	board->drawBoard();
}
void UIManager::requestPlayerTextureUpdate(_house whichhouse,
		uint8_t whichplayer, SDL_Rect srcRect, SDL_Rect DestRect) {
	//SDL_Texture *playerTex;
	cout<<" [UI][reqPlTex_UP]: Entry"<<endl;
	std::string texture = "assets/player/" + std::to_string(whichhouse) + "-"
			+ std::to_string(whichplayer+1)+".png";
	SDL_Surface *tempSurface = IMG_Load(texture.c_str());
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer.renderer,
			tempSurface);
	SDL_FreeSurface(tempSurface);
	SDL_RenderCopy(renderer.renderer, tex, &srcRect, &DestRect);
	cout<<" [UI][reqPlTex_UP]: Exit"<<endl;
}

UIManager::UIManager() {
	cout<<"[UI][Constr]: Entry"<<endl;
//TODO Change default board argument from GOT to user input
	onBoardingBackground = nullptr;
	dieTexture = nullptr;
	font = nullptr;
	gameTypeTexture = nullptr;
	init("Ludo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 960,
			false);
	cout<<"[UI][Constr]: Exit"<<endl;
}
void UIManager::createBoard(GameType gameType) {
	cout<<"[UI][CreatBoard]: Entry"<<endl;
	board = new Board(gameType, &renderer);
	cout<<"[UI][CreatBoard]: Exit"<<endl;
}
UIManager::~UIManager() {
	// TODO Auto-generated destructor stub
}

SDL_Texture *UIManager::giveBackTexture(texType tex) {
	cout<<"[UI][giveBakText]: Entry"<<endl;
	if (tex == _ONBOARDING){
		cout<<"[UI][giveBakText]: Entry"<<endl;
		return onBoardingBackground;}
	else if (tex == _DIEFACE){
		cout<<"[UI][giveBakText]: Entry"<<endl;
		return dieTexture;}
	else{
		cout<<"[UI][giveBakText]: Entry"<<endl;
		return nullptr;}
}
void UIManager::renderClear() {
	SDL_RenderClear(renderer.renderer);
}

void UIManager::renderPresentTexture() {
	SDL_RenderPresent(renderer.renderer);
}
void UIManager::renderNewTexture(texType tex) {
	cout<<"[UI][renNewTex]: Entry"<<endl;
	SDL_RenderClear(renderer.renderer);
	setTexture(tex);
	SDL_RenderPresent(renderer.renderer);
	cout<<"[UI][renNewTex]: Exit"<<endl;
}

void UIManager::setTexture(texType tex, int dieFace) {
	cout<<"[UI][setTex]: Entry"<<endl;
	SDL_Rect srcRect, destRect;
	if (tex == _ONBOARDING || dieFace == 0) {
		// x,y,w,h
		srcRect = {0, 0, 1280, 960};
		destRect = {0, 0, srcRect.w, srcRect.h};
		onBoardingBackground =
		renderer.loadTexture("assets/ludo_background.png");
		SDL_RenderCopy(renderer.renderer, onBoardingBackground, &srcRect, &destRect);
	} else if (tex == _DIEFACE && dieFace != 0) {
		cout<<"setting Die face"<<endl;
		srcRect = {0, 0, 64, 64};
		destRect = {448, 448, srcRect.w, srcRect.h};
		if (dieFace == 1) {
			//TODO WHY LOAD TEXTURE EACH TIME??
			dieTexture = renderer.loadTexture("assets/dice/one.png");
		} else if (dieFace == 2) {
			dieTexture = renderer.loadTexture("assets/dice/two.png");
		} else if (dieFace == 3) {
			dieTexture = renderer.loadTexture("assets/dice/three.png");
		} else if (dieFace == 4) {
			dieTexture = renderer.loadTexture("assets/dice/four.png");
		} else if (dieFace == 5) {
			dieTexture = renderer.loadTexture("assets/dice/five.png");
		} else if (dieFace == 6) {
			dieTexture = renderer.loadTexture("assets/dice/six.png");
		} else if (dieTexture == nullptr)
		cout << "NULL" << endl;
		SDL_RenderCopy(renderer.renderer, dieTexture, &srcRect, &destRect);
	}
	//SDL_RenderPresent(renderer.renderer);
	cout<<"[UI][setTex]: exit"<<endl;
}

void UIManager::clean() {
	cout<<"[UI][clean]: Entry"<<endl;
	SDL_DestroyWindow(window);
	//TODO call object destructor
	SDL_DestroyRenderer(renderer.renderer);
	SDL_Quit();
	cout<< "program terminated from clean" << endl;
	std::exit(0);
}

void UIManager::showPopupMessage(const char *title, const char *body) {
	cout<<"[UI][showPop]: Entry"<<endl;
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, title, body, NULL);
	cout<<"[UI][showPop]: Exit"<<endl;
}

void UIManager::showRules(GameType game) {
	cout<<"[UI][showRule]: Entry"<<endl;
	if (game)
		showPopupMessage("Game Rules", GoTRules.c_str());
	else
		showPopupMessage("Game Rules", traditionalRules.c_str());
	cout<<"[UI][showRule]: Exit"<<endl;
}

