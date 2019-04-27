#include <Siv3D.hpp>

void Main()
{
    const Font font(30);

    while (System::Update())
    {
        String screenName = L"science507";

        HTTPClient client;

        const String url = L"https://twitter.com/" + screenName;

        ByteArray byteArray;
        
        client.download(url, byteArray);

        TextReader reader(std::move(byteArray));

        const String str = reader.readAll();

        int firstIndex = str.indexOf(L"ProfileHeaderCard-nameLink u-textInheritColor js-nav");

        int lastIndex = str.indexOf(L"<", firstIndex);

        String name = str.substr(firstIndex + 54, lastIndex - (firstIndex + 54));

        Println(name);

        WaitKey();
    }
}
