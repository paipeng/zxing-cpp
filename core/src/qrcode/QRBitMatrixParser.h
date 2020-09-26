#pragma once
/*
* Copyright 2016 Nu-book Inc.
* Copyright 2016 ZXing authors
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

namespace ZXing {

class BitMatrix;
class ByteArray;

namespace QRCode {

class Version;
class FormatInformation;

/**
* @author Sean Owen
*/
class BitMatrixParser
{
public:
	/**
	 * @brief Reads version information from the QR Code.
	 * @return {@link Version} encapsulating the QR Code's version, nullptr if neither location can be parsed
	 */
	static const Version* ReadVersion(const BitMatrix& bitMatrix);

	/**
	 * @brief Reads format information from one of its two locations within the QR Code.
	 * @return {@link FormatInformation} encapsulating the QR Code's format info, result is invalid if both format
	 * information locations cannot be parsed as the valid encoding of format information
	 */
	static FormatInformation ReadFormatInformation(const BitMatrix& bitMatrix, bool mirrored);

	/**
	* <p>Reads the bits in the {@link BitMatrix} representing the finder pattern in the
	* correct order in order to reconstruct the codewords bytes contained within the
	* QR Code.</p>
	*
	* @return bytes encoded within the QR Code
	* or empty array if the exact number of bytes expected is not read
	*/
	static ByteArray ReadCodewords(const BitMatrix& bitMatrix, const Version& version, int maskIndex);
};

} // QRCode
} // ZXing
