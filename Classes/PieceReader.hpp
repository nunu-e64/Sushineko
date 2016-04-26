//
//  PieceReader.hpp
//  Sushineko
//
//  Created by Fumiya Amano on 2016/04/26.
//
//

#ifndef PieceReader_hpp
#define PieceReader_hpp

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class PieceReader : public cocostudio::NodeReader
{
public:
    static PieceReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};


#endif /* PieceReader_hpp */
