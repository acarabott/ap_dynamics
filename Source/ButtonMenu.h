/*
  ==============================================================================

    ButtonMenu.h
    Created: 24 Dec 2020 12:43:15pm
    Author:  Johnathan Handy

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "APToggleButton.h"

//==============================================================================
/*
*/
class ButtonMenu  : public juce::Component
{
public:
    ButtonMenu(Ap_dynamicsAudioProcessor&);
    ~ButtonMenu() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    Ap_dynamicsAudioProcessor& audioProcessor;

//    std::unique_ptr<juce::ComboBox> dynType_, compType_;
    APToggleButton dynToggle_, compToggle_, overdriveToggle_;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> dynAttachment_, compAttachment_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ButtonMenu)
};
