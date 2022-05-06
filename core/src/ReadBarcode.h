#pragma once
/*
* Copyright 2019 Axel Waggershauser
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "DecodeHints.h"
#include "ImageView.h"
#include "Result.h"

#ifdef FILENAME_EXPORTS
#define FILENAME_API __declspec(dllexport)
#else
#define FILENAME_API __declspec(dllimport)
#endif
namespace ZXing {

/**
 * Read barcode from an ImageView
 *
 * @param buffer  view of the image data including layout and format
 * @param hints  optional DecodeHints to parameterize / speed up decoding
 * @return #Result structure
 */
	FILENAME_API Result ReadBarcode(const ImageView& buffer, const DecodeHints& hints = {});

// WARNING: this API is experimental and may change/disappear
	FILENAME_API Results ReadBarcodes(const ImageView& buffer, const DecodeHints& hints = {});

} // ZXing

