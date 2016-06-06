#pragma once

#include <Adafruit_TFTLCD.h>
#include "Arduino.h"
#include <avr/pgmspace.h>
#include "Constant.h"
#include "Rhythm.h"
#include "Digit.h"
#include "Fill.h"

#define LCD_RD    A0
#define LCD_WR    A1
#define LCD_CD    A2
#define LCD_CS    A3
#define LCD_RST   A4

namespace Zebra {

  class View: public Adafruit_TFTLCD {
  private:
    Rhythm & rhythmRef;
    float barX;
    float measureX;
    uint16_t playX;
    uint8_t measurePlayCount;
    uint16_t playColor;
    float playXRatio;
    // info rhythm variables
    byte currentInfoRhythmLayout;
    byte previousInfoRhythmLayout;
    uint8_t tempoClean;
    uint8_t metronomeClean;
    uint8_t barClean;
    uint8_t measureClean;
    uint8_t loadClean;
    uint8_t saveClean;
    uint8_t outputClean;
    uint8_t quantizeClean;
    // info layer variables
    uint8_t instAClean;
    uint8_t instBClean;
    int8_t fillNumberClean;
    uint16_t selectedBeatXClean;
    uint16_t selectedBeatYClean;
    bool switchInfoToRhythmFlag;
    bool switchInfoToLayerFlag;
    bool switchInfoBetweenLayersFlag;
    int8_t switchLayer;
    int8_t switchState;
    // private info functions
    void drawInfoNumber(uint8_t num, uint8_t digit, uint16_t xPos, uint16_t yPos, uint16_t color);
    void drawInfoLetter(char letter, uint16_t xPos, uint16_t yPos, uint16_t color);
    void drawInfoDigit(uint8_t digit, uint16_t xPos, uint16_t yPos, uint16_t color);
    // private fill functions
    uint8_t getFillStep(uint8_t fillNum);
    char getFillName(uint8_t fillNum, uint8_t letterNum);
    uint8_t getFillTime(uint8_t fillNum, uint8_t stepNum);
    uint8_t getFillVolume(uint8_t fillNum, uint8_t stepNum);
    uint8_t getFillInst(uint8_t fillNum, uint8_t stepNum);
  public:
    View(Rhythm& rhythm);
    ~View();
    void initialize();
    void update();
    // play functions
    void setPlayX(uint16_t playX_);
    uint16_t getPlayX() const;
    void drawPlayBar();
    void restartPlayBar();
    void resetPlayBar();
    void calculatePlayXRatio();
    // rhythm functions
    void drawRhythmSelected();
    void drawSelectedBeat(const Layer& layer_, const Beat& beat_);
    // layer functions
    void drawLayerAll(Layer& layer_);
    void drawLayerBase(const Layer& layer_);
    void drawLayerSelected(const Layer& layer_);
    void drawLayerBeatActive(const Layer& layer_);
    void drawLayerFillActive(const Layer& layer_);
    void drawLayerMeasure(const Layer& layer_);
    void drawLayerSong(Layer& layer_);
    void drawLayerBeat(const Layer& layer_, uint32_t time_, bool inst_);
    void clearLayerBeat(const Layer& layer_, const Beat& beat_);
    void drawBeatFill(Layer& layer_, uint8_t beatNum_, bool condition);
    void drawLayerFill(Layer& layer_);
    void drawAllLayer();
    void drawAllLayerMeasure();
    void drawAllLayerMeasureSongFill();
    // menu functions
    void drawTempo(bool state);
    void drawMetronome(bool state);
    void drawBar(bool state);
    void drawMeasure(bool state);
    void drawLoad(bool state);
    void drawSave(bool state);
    void drawOutput(bool state);
    void drawQuantize(bool state);

    void drawTempoData();
    void drawMetronomeData();
    void drawBarData();
    void drawMeasureData();
    void drawLoadData();
    void drawSaveData();
    void drawOutputData();
    void drawQuantizeData();

    void drawInfoRhythmAll();
    void drawInfoRhythmBase();
    void drawInfoRhythmTempo();
    void drawInfoRhythmQuantize();
    void drawInfoRhythmBar();
    void drawInfoRhythmMeasure();
    void cleanInfoRhythm();
    // info layer functions
    void drawInfoLayerAll(const Layer& layer_, const Beat& beat_);
    void drawInfoLayerBase();
    void drawInfoLayerInstA(const Layer& layer_);
    void drawInfoLayerInstB(const Layer& layer_);
    void drawInfoFill(const Beat& beat_);
    void cleanInfoFill();
    // info switch functions
    void switchInfoToRhythm();
    void switchInfoToLayer(const Layer& layer_);
    void switchInfoBetweenLayers(const Layer& layer_);
    void checkSwitchInfoToRhythm();
    void checkSwitchInfoToLayer();
    void checkSwitchInfoBetweenLayers();
    // debug functions
    void debug(uint32_t var);
  };
}
