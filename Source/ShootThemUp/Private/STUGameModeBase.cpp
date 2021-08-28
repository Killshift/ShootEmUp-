// Fill out your copyright notice in the Description page of Project Settings.


#include "STUGameModeBase.h"
#include "STUPlayerController.h"
#include "STUBaseCharacter.h"
#include "UI/STUGameHUD.h"


ASTUGameModeBase::ASTUGameModeBase() 
{
    DefaultPawnClass = ASTUBaseCharacter::StaticClass();
    PlayerControllerClass = ASTUPlayerController::StaticClass();
    HUDClass = ASTUGameHUD::StaticClass();
}