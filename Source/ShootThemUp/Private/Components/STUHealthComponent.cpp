// Test Project


#include "Components/STUHealthComponent.h"


USTUHealthComponent::USTUHealthComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

}



void USTUHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	
}
