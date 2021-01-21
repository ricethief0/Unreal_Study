// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


//FString 

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
    Length = HiddenWord.Len();
    
   
    //
    PrintLine(HiddenWord);
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
        return;
    }

    ProcessGuess(Input);
    // = TEXT("cake");
   
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to Boll Cows!"));

    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), Length);
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));

}

void UBullCowCartridge::ProcessGuess(const FString& Input)
{
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You have Won!"));
        EndGame();
        return;
    }

   

    
    if (Input.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i letters long"), Length);
        PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
        return;
    }

    if (!IsIsogram(Input))
    {
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }
    PrintLine(TEXT("Lost a life!"));
    --Lives;

    if (Lives <= 0)
    {
        PrintLine(TEXT("You have no lives left!"), Length);
        EndGame();
        return;
    }
    
    
}

bool UBullCowCartridge::IsIsogram(FString word)
{
    return true;
}

