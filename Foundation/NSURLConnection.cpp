/****************************************************************************
	Cocos  Project
			hosting	github.com
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include <Foundation/NSURLConnection.h>
#include <Foundation/NSData.h>
#include <Foundation/NSURLResponse.h>
#include <curl/curl.h>
size_t
	writeData(void *buffer, size_t size, size_t count, void *stream)
{
	return fwrite(buffer,size,count,(FILE*)stream);
}
void
	NSURLConnection::sendAsynchronousRequest_queue_completionHandler
	(NSURLRequest* request ,NSOperationQueue* queue ,NSCodeBlock block)
{
	char uni[20];
	sprintf(uni,"%d",request);

	FILE *fp;
	char outfilename[200];
	strcpy(outfilename,CCFileUtils::fullPathFromRelativePath(""));
	strcat(outfilename,uni);
	strcat(outfilename,"DATA.png");
	fp = fopen(outfilename,"wb");

	CURL* curl = request->URL()->getcurl();
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	CURLcode code = curl_easy_perform(curl);
	
	fclose(fp);

	NSData* data = NSData::dataWithContentsOfFile(NSSTR(outfilename));
	//todo NSErro class for nil
	block(nil,data,nil);
}
void
	NSURLConnection::dealloc()
{
}