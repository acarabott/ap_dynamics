/*
  ==============================================================================

    MixerButton.cpp
    Created: 21 Jan 2021 7:10:13pm
    Author:  Johnathan Handy

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MixerButton.h"

//==============================================================================
MixerButton::MixerButton(Ap_dynamicsAudioProcessor& p) : audioProcessor (p)
{
}

MixerButton::~MixerButton()
{
}

void MixerButton::paint (juce::Graphics& g)
{

    // Background
    g.setGradientFill (
            juce::ColourGradient (juce::Colours::grey, getWidth() / 2, getHeight() / 2,juce::Colours::darkgrey,0,0,true)
    );
    g.fillRoundedRectangle (0, 0, getWidth(), getHeight(), 10);
    auto bounds = getLocalBounds();
    bounds.removeFromTop(10).removeFromBottom(10);

    // Labels
    g.setColour(juce::Colours::snow);
    g.setFont(labelFont_.withHeight (24.0f));
    g.drawFittedText("clean", bounds.removeFromTop(getHeight() / 3 - 10),
                     juce::Justification::centred, 1);
    g.drawLine(10, getHeight() / 3, getWidth() - 10, getHeight() / 3, 1);
    g.drawFittedText("dirty", bounds.removeFromTop(getHeight() / 3),
                     juce::Justification::centred, 1);
    g.drawLine(10, getHeight() / 3 * 2, getWidth() - 10, getHeight() / 3 * 2, 1);
    g.drawFittedText("dirtier", bounds,
                     juce::Justification::centred, 1);

    auto bubbleBounds = juce::Rectangle<float> (pointerPos_.getX() - 10, pointerPos_.getY() - 10, 20, 20);

    // Pointer
    g.setGradientFill(juce::ColourGradient(juce::Colour(0xFF00FA92).withAlpha(0.3f),
                         bubbleBounds.getCentreX(),
                         bubbleBounds.getCentreY(),
                         juce::Colour(0xFFD783FF),
                         bubbleBounds.getX(), bubbleBounds.getY(), true)
                         );
    g.fillEllipse(bubbleBounds);
}

void MixerButton::resized()
{
}

void MixerButton::mouseDown(const juce::MouseEvent& event) {
    auto bounds = getLocalBounds();

    if (bounds.contains (event.getMouseDownPosition())) {
        pointerPos_ = event.getMouseDownPosition();
        mixValue_ = juce::jmap(pointerPos_.getY(), 0, getHeight(),
                               0, 100);
        audioProcessor.setMixValue (mixValue_);
    }
}

void MixerButton::mouseDrag(const juce::MouseEvent& event) {
    auto bounds = getLocalBounds();

    if (bounds.contains (event.getMouseDownPosition())) {
        pointerPos_ = event.getPosition();
        mixValue_ = juce::jmap(pointerPos_.getY(), 0, getHeight(),
                               0, 100);
        audioProcessor.setMixValue (mixValue_);
    }
}