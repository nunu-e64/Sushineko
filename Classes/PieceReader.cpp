//
//  PieceReader.cpp
//  Sushineko
//
//  Created by Fumiya Amano on 2016/04/26.
//
//

#include "PieceReader.hpp"
#include "Piece.hpp"
using namespace cocos2d;

static PieceReader* _instancePieceReader = nullptr;

PieceReader* PieceReader::getInstance()
{
    if (!_instancePieceReader)
    {
        _instancePieceReader = new PieceReader();
    }
    return _instancePieceReader;
}

void PieceReader::purge()
{
    CC_SAFE_DELETE(_instancePieceReader);
    
}

Node* PieceReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
    Piece* node = Piece::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}