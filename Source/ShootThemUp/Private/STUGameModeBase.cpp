// Fill out your copyright notice in the Description page of Project Settings.


#include "STUGameModeBase.h"
#include "STUPlayerController.h"
#include "STUBaseCharacter.h"


ASTUGameModeBase::ASTUGameModeBase() 
{
    DefaultPawnClass = ASTUBaseCharacter::StaticClass();
    PlayerControllerClass = ASTUPlayerController::StaticClass();
}