# MiniLibX

so_long 프로젝트에는 **`minilibx_opengl.tgz` `minilibx_mms_20200219_beta.tgz`** 압축 파일이 제공된다. 이 두 파일을 설치 후 압축을 해제한 뒤, 두 폴더를 git repository로 가져온다.

# 1. Manual

`minilibx_mmx_20200219/man/man3/` 폴더 안에 매뉴얼들이 있다.

`man minilibx_mmx_20200219/man/man3/<파일명>` 명령어를 통해 매뉴얼을 볼 수 있다. 

(클러스터 맥 환경이라면 `man /usr/share/man/man3/` 폴더 안에도 매뉴얼이 있다. (다른 버전인 것 같다.))

## 1.1. mlx

- NAME
    - MiniLibX - Simple Window Interface Library for students
- SYNOPSYS
    
    ```c
    #include <mlx.h>
    
    void  *mlx_init();
    ```
    
- DESCRIPTION
    - MiniLibX is an easy way to create graphical software, without any X-Window/X11 programming knowledge under Unix/Linux, nor any AppKit programming knowledge under MacOS. It provides simple window creation, a drawing tool, image and basic events management.
    - 번역
        - MiniLibX는 Unix/Linux에서 X-Window/X11 프로그래밍 지식이나 MacOS에서 AppKit 프로그래밍 지식 없이 그래픽 소프트웨어를 쉽게 만들 수 있는 방법이다. 간단한 window 만들기, 그리기 도구, 이미지 및 기본 이벤트 관리 기능을 제공한다.
- Unix/Linux: X-WINDOW CONCEPT
    - X-Window is network-oriented graphical system for Unix. It is based on two main parts:
        - On one side, your software wants to draw something on the screen and/or get keyboard & mouse entries.
        - On the other side, the X-Server manages the screen, keyboard and mouse(It is often referred to as a “display”).
    - A network connection must be established between these two entities to send drawing orders (from the software to the X-Server), and key-board/mouse events (from the X-Server to the software).
    - Nowadays, most of the time, both run on the same computer.
    - 번역
        - X-Window는 Unix용 네트워크 지향 그래픽 시스템이다. 두 가지 주요 부분을 기반으로 한다.
            - 한편으로는 소프트웨어가 화면에 무언가를 그리거나 키보드 및 마우스 항목을 가져오려고 한다.
            - 한편 X서버는 화면, 키보드, 마우스를 관리한다. (흔히 “디스플레이"라고 한다.)
        - 그리기 명령(from the software to the X-Server)과 키보드/마우스 이벤트(from the X-Server to the software로)를 전송하려면 이 두 엔티티 사이에 네트워크 연결이 설정되어야 한다.
        - 요즘, 대부분의 경우, 둘 다 같은 컴퓨터에서 실행된다.
- MacOS: WINDOW SERVER AND GPU
    - Your software  interacts directly with the Window server who handles the cohabitation(동거) on the screen with other software and the event system, and interacts with the GPU to handle all drawing stuff.
    - 번역
        - 너의 software는 스크린 상에서 다른 software 및 event system과 동거를 처리하는 Window server와 직접 상호 작용하고, GPU와 상호 작용하여 모든 그림 그리기를 처리한다.
- INCLUDE FILE
    - mlx.h should be included for a correct use of the MiniLibX API. It only contains function prototypes, no structure is needed.
    - 번역
        
        MiniLibX API를 올바르게 사용하기 위해 mlx.h가 포함되어야 한다. function prototypes만 포함하며 structure는 필요하지 않다.
        
- LIBRARY FUNCTIONS
    - First of all, you need to initialize the connection between your software and the display. Once this connection is established, you’ll be able to use other MiniLibX functions to send and receive the messages from the display, like “I want to draw a yellow pixel in this window” or “did the user hit a key?”.
    - The `mlx_init` function will create this connection. No parameters are needed, and it will return a void * identifier, used for further calls to the library routines.
    - All other MiniLibX functions are described in the following man pages:
        - mlx_new_window: manage windows
        - mlx_pixel_put: draw inside window
        - mlx_new_image: manipulate images
        - mlx_loop: handle keyboard or mouse events
    - 번역
        - 먼저, 너의 software와 display 사이의 연결을 초기화 해야한다. 이 연결이 설립되면, 다른 MiniLibX functions를 사용하여 display로부터 "이 창에 노란색 픽셀을 그린다." 또는 "사용자가 키를 눌렀습니까?"와 같은 메시지를 보내고 받을 수 있다.
        - `mlx_init` 함수가 이 연결을 생성한다. 매개변수가 필요하지 않으며, 라이브러리 루틴에 대한 추가 호출에 사용되는 void * 식별자를 반환한다.
        - MiniLibX의 다른 모든 함수들은 아래의 man page에 설명되어 있다.
            - mlx_new_window: windows 관리
            - mlx_pixel_put: window 안쪽에 그리기
            - mlx_new_image: 이미지 조종
            - mlx_loop: 키보드or마우스 이벤트 처리
- LINKING MiniLibX
    - To use MiniLibX functions, you may need to link your software with several libraries, including the MiniLibX library itself.
    - On Unix/Linux, simply add the following arguments at linking time:
        - `-lmlx -lXext -lX11`
    - On MacOS, the dynamic Metal library will find on its own the missing components:
        - `-lmlx`
    - and still on MacOS, the static OpenGL version will need:
        - `-lmlx -framework OpenGL -framework AppKit -lz`
    - You may also need to specify the path to these libraries, using the -L flag.
    - 번역
        - MiniLibX 함수를 사용하기 위해, 너의 software를 MiniLibX 라이브러리 자체를 포함해 여러 라이브러리와 link 해야할지도 모른다.
        - Unix/Linux의 경우 링크 시간에 다음 인자를 추가하기만 하면 된다.
            - `-lmlx -lXext -lX11`
        - MacOS에서 동적 Metal 라이브러리는 누락된 구성 요소를 스스로 찾는다.
            - `lmlx`
        - MacOS에서 정적 OpenGL 버전에는 다음이 필요하다.
            - `-lmlx -framework OpenGL -framework AppKit -lz`
        - 또한 -L 플래그를 사용하여 이러한 라이브러리의 경로를 지정해야 할 수도 있다.
- RETURN VALUES
    - If `mlx_init()` fails to set up the connection to the display, it will return NULL, otherwise a non-null pointer is returned as a connection identifier.

## 1.2. mlx_new_window

- NAME
    - MiniLibX - Managing windows
- SYNOPSYS
    
    ```c
    void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
    int mlx_clear_window(void *mlx_ptr, void *win_ptr);
    int mlx_destroy_window(void *mlx_ptr, void *win_ptr);
    ```
    
- DESCRIPTION
    - The `mlx_new_window()` function creates a new window on the screen, using the `size_x` and `size_y`  parameters to determine its size, and `title` as the text that should be displayed in the windows’ title bar. The `mlx_ptr` parameter is the connection identifier returned by `mlx_init()` (see the mlx man page). `mlx_new_window()` returns a void * window identifier that can be used by other MiniLibX calls. Note that the MiniLibX can handle an arbitrary number of separate windows.
    - `mlx_clear_window()` and `mlx_destroy_window()` respectively clear (in black) and destroy the given window. They both have the same parameters: `mlx_ptr` is the screen connection identifier, and `win_ptr` is a window identifier.
    - 번역
        - `mlx_new_window()` 함수는 screen 위에 새로운 window를 생성하는데, window의 size를 결정하기 위해 `size_x` 및 `size_y` 매개 변수를 사용하고, window의 제목 표시줄에 표시되어야 하는 텍스트로 `title` 매개 변수를 사용한다. `mlx_ptr` 매개 변수는 `mlx_init()`에서 리턴받은 연결 식별자이다 (mlx man page를 봐라). `mlx_new_window()`는 다른 MiniLibX 호출에서 사용할 수 있는 void * window 식별자를 반환한다. MiniLibX는 임의의 수의 개별 windows를 처리할 수 있다.
        - `mlx_clear_window()` 와 `mlx_destroy_window()` 는 각각 주어진 window를 지우고 삭제한다. 이 둘은 같은 매개 변수를 가진다: `mlx_ptr` 는 screen 연결 식별자이고, `win_ptr` 는 window 식별자이다.
- RETURN VALUES
    - If `mlx_new_window()` fails to create a new window (for whatever reason), it will return NULL, otherwise a non-null pointer is returned as a window identifier.
    - `mlx_clear_window` and `mlx_destroy_window` right now return nothing.

## 1.3. mlx_pixel_put

- NAME
    - MiniLibX - Drawing inside windows
- SYNOPSYS
    
    ```c
    int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
    int mlx_string(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
    ```
    
- DESCRIPTION
    - The `mlx_pixel_put()` function draws a defined pixel in the window `win_ptr` using the `(x, y)` coordinates, and the specified `color`. The origin `(0, 0)` is the upper left corner of the window, the `x` and `y` axis respectively pointing right and down. The connection identifier, `mlx_ptr`, is needed.
    - Parameters for `mlx_string_put()` have the same meaning. Instead of a simple pixel, the specified `string` will be displayed at `(x, y)`.
    - Both functions will discard any display outside the window. This makes `mlx_pixel_put` slow. Consider using images instead.
    - 번역
        - `mlx_pixel_put()` 함수는 `(x, y)` 좌표와 지정된 `color`를 사용하여 `win_ptr` 창(window)에 정의된 pixel을 그린다. 원점 `(0, 0)`은 창의 왼쪽 상단 모서리고, `x`축과 `y`축은 각각 오른쪽과 아래쪽을 가리킨다. 연결 식별자 `mlx_ptr`이 필요하다.
        - `mlx_string_put()`에 대한 매개 변수는 같은 의미이다. 단순 pixel 대신, 지정된 `string`이 `(x, y)`에 표시된다.
        - 두 함수 모두 window 밖의 모든 display를 폐기한다. 이것 때문에 `ml_pixel_put`이 느리다. 대신 images 사용을 고려해라.
- COLOR MANAGEMENT
    - The `color` parameter has an integer type. The displayed color needs to be encoded in this integer, following a defined scheme. All displayable colors can be split in 3 basic color: red, green and blue. Three associated values, in the 0-255 range, represent how much of each color is mixed up to create the original color. Theses three values must be set inside the integer to display the right color. The three least significant bytes of this integer are filled as shown in the picture below:
        |  0  |  R  |  G  |  B  |   color integer
        +---+---+---+---+
    - While filling the integer, make sure you avoid endian problems. Remember that the “blue” byte should always be the least significant one.
    - Depending on hardware capabilities, the most significant bit can handle transparency. Beware, at the opposite of the OpenGL classics, it does not represent opacity.
    - 번역
        - `color` 매개 변수는 정수 타입이다. 표시된 색상은 다음과 같이 정의된 체계(scheme)에 따라 이 정수로 인코딩되어야 한다.
            - 표시 가능한 모든 색상은 red, green, blue의 세 가지 기본 색상으로 분할할 수 있다.
            - 0-255 범위의 세 개의 관련 값은 원래 색을 만들기 위해 각 색상이 혼합된 정로를 표현한다.
            - 이 세 개의 값은 올바른 색을 표시하기 위해 정수 안에 설정되어야 한다.
            - 아래 그림과 같이 이 정수의 최하위 바이트 3개가 채워진다.
                |  0  |  R  |  G  |  B  |   color integer
                +---+---+---+---+
        - 정수를 채우는 동안, endian(메모리 속에서의 데이터 순서를 정하는 시스템에 관련된) 문제가 발생하지 않도록 해라. “blue” 바이트는 항상 가장 덜 중요한 것 이어야 한다.
        - 하드웨어 능력에 따라, 가장 중요한 비트가 투명성을 처리할 수 있다. OpenGL 클래식과는 반대로 불투명함을 나타내지 않는다는 점에 유의해라.

## 1.4. mlx_new_image

- NAME
    - MiniLibX - Manipulating images (이미지 조작)
- SYNOPSYS
    
    ```c
    void *mlx_new_image(void *mlx_ptr, int width, int height);
    char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
    int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
    unsigned int mlx_get_color_value(void *mlx_ptr, int color);
    void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);
    void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *witdh, int *height);
    void *mlx_png_file_to_image(void *mlx_ptr, char *filename, int *with, int *height);
    int mlx_destroy_image(void *mlx_ptr, void *img_ptr);
    ```
    
- DESCRIPTION
    - `mlx_new_image()` create a new image in memory. It returns a `void *` identifier needed to manipulate this image later. It only needs the size of the image to be created, using the `width` and `height` parameters, and the `mlx_ptr` connection identifier.
    - The user can draw inside the image (see below), and can dump the image inside a specified window at any time to display it on the screen. This is done using `mlx_put_iamge_to_window()`. Three identifiers are needed here, for the connection to the display, the window to use, and the image (respectively `mlx_ptr`, `win_ptr`, and `img_ptr`). The `(x, y)` coordinates define where the image should be placed in the window.
    - `mlx_get_data_addr()` returns information about the created image, allowing a user to modify it later. The `img_ptr` parameter specifies the image to use. The three next parameter should be the addresses of three different valid integers. `bits_per_pixel` will be filled with the number of bits needed to represent a pixel color (also called the depth of the image). `size_line` is the number of bytes used to store one line of the image in memory. This information is needed to move from one line to another in the image. `endian` tells you wether the pixel color in the image needs to be stored in little endian (`endian` == 0), or big endian (`endian` == 1).
    - `mlx_get_data_addr` returns a `char *` address that represents the beginning of the memory area where the image is stored. From this address, the first `bits_per_pixel` bits represent the color of the first pixel in the first line of the image. The second group of `bits_per_pixel` bits represent the second pixel of the first line, and so on. Add `size_line` to the address to get the beginning of the second line. You can reach any pixels of the image that way.
    - `mlx_destroy_image` destroys the given image (`img_ptr`).
    - 번역
        - `mlx_new_image()`는 메모리에 새 이미지를 생성한다. 나중에 이 이미지를 조작하는데 필요한 `void *`  식별자를 반환한다. `width` 및 `height` 매개 변수와 `mlx_ptr` 연결 식별자를 사용하여 생성할 이미지의 크기만 있으면 된다.
        - 사용자는 이미지 내부를 그릴 수 있으며, 언제든지 지정된 window 내에 이미지를 덤프하여 화면에 표시할 수 있다. 이 작업은 `mlx_put_iamge_to_window()`를 사용하여 수행한다. 여기에는 디스플레이 연결, 사용할 창 연결, 이미지 연결을 위한 세 가지 식별자(각각 `mlx_ptr`, `win_ptr`, `img_ptr`)가 필요하다. (`x`, `y`) 좌표는 window에서 이미지를 배치할 위치를 정의한다.
        - `mlx_get_data_addr`은 생성된 이미지에 대한 정보를 반환하므로 사용자는 나중에 이미지를 수정할 수 있다. `img_ptr` 매개 변수는 사용할 이미지를 지정한다. 세 개의 다음 매개 변수는 세 개의 서로 다른 유효한 정수의 주소여야 한다. `bits_per_pixel`은 픽셀 색상을 나타내는 데 필요한 비트 수(이미지의 깊이 라고도 함)로 채워진다. `size_line`은 이미지 한 줄을 메모리에 저장하는 데 사용되는 바이트 수다. 이 정보는 이미지의 한 라인에서 다른 라인으로 이동하는데 필요하다. `endian`은 이미지의 픽셀 색상을 little endian(`endian` == 0)과 big endian(`endian` == 1) 중 어디에 저장해야 하는지 알려준다.
        - `mlx_get_data_addr`은 이미지가 저장된 메모리 영역의 시작을 나타내는 `char *` 주소를 반환한다. 이 주소에서, 첫 번째 `bits_per_pixel` 비트는 이미지의 첫 번째 줄에 있는 첫 번째 픽셀의 색상을 나타낸다. `bits_per_pixel` 비트의 두 번째 그룹은 첫 번째 줄의 두 번째 픽셀을 나타낸다(세 번째, 네 번째도 동일). 주소에 `size_line`을 추가하여 두 번째 줄의 시작을 가져온다. 그런 방식으로 이미지의 모든 픽셀에 도달할 수 있다.
        - `mlx_destroy_image`는 주어진 이미지(`img_ptr`)를 삭제한다.
- STORING COLOR INSIDE IMAGES
    - Depending on the display, the number of bits used to store a pixel color can change. The user usually represents a color in RGB mode, using one byte for each component (see `mlx_pixel_put` manual). This must be translated to fit the `bits_per_pixel`  requirement of the image, and make the color understandable to the display. That is the purpose of the `mlx_get_color_value()` function. It takes a standard RGB `color` parameter, and returns an `unsigned int` value. The `bits_per_pixel` least significant bits of this value can be stored in the image. You can avoid using this function if there is no conversion needed (eg. in case of 24 bits depth, or 42 bits depth).
    - Keep in mind that the least significant bits position depends on the local computer’s endian. If the endian of the image differs from the local endian (which should only occurs in a X11 network environment), then the value should be transformed before being used.
    - 번역
        - 디스플레이에 따라 픽셀 색상을 저장하는 데 사용되는 비트 수가 변경될 수 있다. 사용자는 일반적으로 각 구성 요소에 대해 1바이트를 사용하여 RGB 모드에서 색상을 나타낸다(`mlx_pixel_put` 매뉴얼 참조). 이것은 이미지의 `bits_per_pixel` 요구 사항에 맞도록 변환되어야 하며, 디스플레이가 색상을 이해할 수 있도록 해야 한다. 이것이 `mlx_get_color_value()` 함수의 목적이다. 표준 RGB 색상 매개 변수를 사용하고, `unsigned int` 값을 반환한다. 이 값의 `bits_per_pixel` 최소 유의 비트는 이미지에 저장될 수 있다. 변환이 필요하지 않은 경우(예: 24비트 깊이 또는 42비트 깊이), 이 기능을 사용하지 않도록 할 수 있다.
        - 최하위 비트 위치는 로컬 컴퓨터의 endian에 따라 달라진다는 것을 명심해라. 이미지의 endian이 로컬 endian과 다를 경우(X11 네트워크 환경에서만 발생함), 값이 사용되기 전에 변환돼야 한다.
- XPM AND PNG IMAGES
    - The `mlx_xpm_to_image()`, `mlx_xpm_file_to_iamge()` and `mlx_png_file_to_image()` functions will create a new image the same way. They will fill it using the specified `xpm_data` or `filename`, depending on which function is used. Note that MiniLibX does not use the standard Xpm and png libraries to deal with xpm and png images. You may not be able to read all types of xpm and png images. It however handles transparency.
    - 번역
        - `mlx_xpm_to_image()`, `mlx_xpm_file_to_iamge()` 및 `mlx_png_file_to_image()` 함수는 동일한 방법으로 새 이미지를 생성한다. 사용되는 함수에 따라 지정된 `xpm_data` 또는 `filename`을 사용하여 이 값을 채운다. MiniLibX는 표준 Xpm 및 png 라이브러리를 사용하여 xpm 및 png 이미지를 처리하지 않는다. 일부 유형의 xpm 및 png 이미지를 읽지 못할 수도 있다. 그러나 투명도를 처리한다.
- RETURN VALUES
    - The four functions that create images, `mlx_new_image()`, `mlx_xpm_to_image()`, `mlx_xpm_file_to_image()` and `mlx_png_file_to_image()`, will return NULL if an error occurs. Otherwise they return a non-null pointer as an image identifier.

## 1.5. mlx_loop

- NAME
    - MiniLibX - Handle events
- SYNOPSYS
    
    ```c
    int mlx_loop(void *mlx_ptr);
    int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
    int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
    int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
    int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
    ```
    
- EVENTS
    - The graphical system is bi-directional. On one hand, the program sends orders to the screen to display pixels, images, and so on. On the other hand, it can get information from the keyboard and mouse associated to the screen. To do so, the program receives “events” from the keyboard or the mouse.
    - 번역
        - 그래픽 시스템은 양방향이다. 한 편은, 프로그램이 픽셀, 이미지 등을 표시하기 위해 screen에 명령을 보낸다. 다른 한 편으로는, screen에 연결된 키보드와 마우스로부터 정보를 얻을 수 있다. 이를 위해, 프로그램은 키보드나 마우스로부터 "events"를 수신한다.
- DESCRIPTION
    - To receive events, you must use `mlx_loop()`. This function never returns. It is an infinite loop that waits for an event, and then calls a user-defined function associated with this event. A single parameter is needed, the connection identifier `mlx_ptr` (see the `mlx` manual).
    - You can assign different functions to the three following events:
        - A key is pressed.
        - The mouse button is pressed.
        - A part of the window should be re-drawn (this is called an “expose” event, and it is your program’s job to handle it in the Unix/Linux X11 environment, but at the opposite it never happens on MacOS).
    - Each window can define a different function for the same event.
    - The three functions `mlx_key_hook()`, `mlx_mouse_hook()`, and `mlx_expose_hook()` work exactly the same way. `funct_ptr` is a pointer to the function you want to be called when an event occurs. This assignment is specific to the window defined by the `win_ptr` identifier. The `param` address will be passed to the function everytime it is called, and should be used to store the parameters it might need.
    - The syntax for the `mlx_loop_hook()` function is identical to the previous ones, but the given function will be called when no event occurs.
    - When it catches an event, the MiniLibX calls the corresponding function with fixed parameter:
        - `expose_hook(void *param);`
        - `key_hook(int keycode, void *param);`
        - `mouse_hook(int button, int x, int y, void *param);`
        - `loop_hook(void *param);`
    - These function names are arbitrary. They here are used to distinguish parameters according to the event. These functions are NOT part of the MiniLibX,.
    - `param` is the address specified in the `mlx_*_hook` calls. This address is never used nor modified by the MiniLibX. On key and mouse events, additional information is passed: `keycode` tells you which key is pressed (with X11, look for the include file `“keysymdef.h”` with MacOS, just try), (`x`, `y`) are the coordinates of the mouse click in the window, and `button` tells you which mouse button was pressed.
    - 번역
        - 이벤트를 받기위해, `mlx_loop()`을 사용해야 한다. 이 함수는 절대 반환하지 않는다. 이벤트를 기다리다가, 이 이벤트와 관련된 사용자 정의 함수를 호출하는 무한 루프이다. 연결 식별자 `mlx_ptr`이라는 단일 매개 변수가 필요하다(`mlx` 설명서 참조).
        - 다음 세 가지 이벤트에 서로 다른 함수를 할당할 수 있다:
            - 키 입력
            - 마우스 버튼 입력
            - window의 일부를 다시 그려져야 함 (”expose” 이벤트)
                - 유닉스/리눅스 X11 환경에서는 처리할 프로그램의 작업
                - MacOS에서는 전혀 발생하지 않음
        - 각 window는 동일한 이벤트에 대해 서로 다른 함수를 정의할 수 있다.
        - 세 가지 함수 `mlx_key_hook()`, `mlx_mouse_hook()` 및 `mlx_expose_hook()`은 정확히 동일한 방식으로 작동한다. `funct_ptr`은 이벤트가 발생할 때 호출되길 원하는 함수에 대한 포인터다. 이 할당은 `win_ptr` 식별자에 의해 정의된 window에 한정된다. `param` 주소는 호출될 때마다 함수에 전달되며, 필요할 수 있는 매개 변수를 저장하는 데 사용되어야 한다.
        - `mlx_loop_hook()` 함수의 syntax는 이전 함수와 동일하지만, 이벤트가 발생하지 않을 때 주어진 함수가 호출된다.
        - 이벤트를 포착하면 MiniLibX는 고정 매개 변수를 사용하여 해당 함수를 호출한다:
            - `expose_hook(void *param);`
            - `key_hook(int keycode, void *param);`
            - `mouse_hook(int button, int x, int y, void *param);`
            - `loop_hook(void *param);`
        - 이러한 함수 이름은 임의이다(위의 함수). 여기서는 이벤트에 따라 매개 변수를 구별하는 데 사용된다. 이러한 기능은 MiniLibX의 일부가 아니다.
        - `param`은 `mlx_*_hook` 호출에 지정된 주소이다. 이 주소는 MiniLibX에서 절대 사용되거나 수정되지 않는다. key 및 mouse 이벤트에서, 추가 정보가 전달된다. `keycode`는 어떤 키가 눌렸는지 알려준다(X11의 경우 `"keysymdef.h"`포함 파일을 봐, MacOS에서는 그냥 해봐), (`x`, `y`)는 window에서 마우스 클릭의 좌표이며, `button`은 어떤 마우스 버튼이 눌렸는지 알려준다.
- GOING FURTHER WITH EVENTS
    - The MiniLibX provides a much generic access to other available events. The `mlx.h` include define `mlx_hook()` in the same manner `mlx_*_hook` functions work. The event and mask values will be taken from the X11 include file “X.h”. Some MacOS events are mapped to these values, when it makes sense, and the mask is not used in MacOS.
    - See source code of the MiniLibX to find out how it will call your own function for a specific event.
    - 번역
        - MiniLibX는 사용 가능한 다른 이벤트에 대한 일반적인 액세스를 제공한다. `mlx.h`는 `mlx_*_hook` 함수가 작동하는 것과 동일한 방식으로 `mlx_hook()`을 정의한다. 이벤트 및 마스크 값은 "X.h" 파일을 포함하는 X11에서 가져온다. 일부 MacOS 이벤트는 이 값에 매핑되며, 마스크는 MacOS에서 사용되지 않는다.
        - MiniLibX가 특정 이벤트에 대해 사용자 자신의 함수를 호출하는 방법을 알아보려면 MiniLibX의 소스 코드를 참조해라.

---

# 2. Hooking into events

## 2.1. hooking

- **후킹(영어: hooking)**은 소프트웨어 공학 용어로, 운영 체제나 응용 소프트웨어 등의 각종 컴퓨터 프로그램에서 **소프트웨어 구성 요소 간에 발생하는 함수 호출, 메시지, 이벤트 등을 중간에서 바꾸거나 가로채는 명령, 방법, 기술이나 행위**를 말한다. 이때 이러한 **간섭된 함수 호출, 이벤트 또는 메시지를 처리하는 코드**를 **훅(영어: hook)**이라고 한다.

## 2.2. mlx_hook

- 이벤트 후크는 MiniLibX가 제공하는 가장 강력한 도구 중 하나이다. 간단한 후크 등록 기능 호출로 앞서 언급한 `mlx_*_hook()` 기능을 수행할 수 있다.

```c
void mlx_hook(void *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
```

- MacOS - Cocoa (AppKit) 및 OpenGL - 버전에서 MiniLibX는 X11 이벤트를 부분적으로 지원하며 X11 마스크를 지원하지 않는다(`mlx_hook`의 `x_mask` 인수는 무용지물이므로 0으로 유지).

## 2.2. Prototype of event functions

- 이벤트 함수는 후킹 이벤트에 따라 프로토타입이 다르다.
    
    
    | Hooking event | code | Prototype |
    | --- | --- | --- |
    | ON_KEYDOWN | 2 | int (*f)(int keycode, void *param) |
    | ON_KEYUP* | 3 | int (*f)(int keycode, void *param) |
    | ON_MOUSEDOWN* | 4 | int (*f)(int button, int x, int y, void *param) |
    | ON_MOUSEUP | 5 | int (*f)(int button, int x, int y, void *param) |
    | ON_MOUSEMOVE | 6 | int (*f)(int x, int y, void *param) |
    | ON_EXPOSE* | 12 | int (*f)(void *param) |
    | ON_DESTROY | 17 | int (*f)(void *param) |

## 2.3. Hooking alias

- MiniLibX api는 hooking function 별칭이 있다:
    - `mlx_expose_hook` function is an alias of mlx_hook on expose event (`12`).
    - `mlx_key_hook` function is an alias of mlx_hook on key up event (`3`).
    - `mlx_mouse_hook` function is an alias of mlx_hook on mouse down event (`4`).

---

# 3. Include mlx library to compile

## 3.1. cluster mac version

- 클러스터 맥에는 mlx 라이브러리가 존재한다.
    - 경로: `/usr/local/lib/libmlx.a`
- 정적 라이브러리이다. 컴파일시 `-framework OpenGL -framework AppKit`를 추가해준다.
- `cc so_long.c -lmlx -framework OpenGL -framework AppKit -o so_long`

## 3.2. opengl version

- 과제에서 제공하는 두 가지 폴더 중, `minilibx_opengl_20191021`
- 정적 라이브러리이다. 컴파일시 `-framework OpenGL -framework AppKit`를 추가해준다.
- 라이브러리를 검색할 디렉토리 경로를 추가해준다. (`-L flag`)
- `cc so_long.c -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -o so_long`

## 3.3. mms version

- 과제에서 제공하는 두 가지 폴더 중, `minilibx_mms_20200219`
- 동적 라이브러리이다. 라이브러리 파일을 현재경로로 복사해준 뒤 컴파일 해야 한다.
- 라이브러리를 검색할 디렉토리 경로를 추가해준다. (`-L flag`)
- `cc so_long.c -L./ -lmlx -o so_long`

## 3.4. Makefile

- local / opengl / mms 중 뭘 선택하냐에 따라 디테일한 부분은 수정해야 한다. (make clean 여부, lib 파일 복사 여부 등)

```makefile
NAME = so_long

SRCS = so_long.c
OBJS = $(SRCS:.c=.o)

# openGL
MLX_NAME = libmlx.a
MLX_DIR = ./minilibx_opengl_20191021/

# mms
# MLX_NAME = libmlx.dylib
# MLX_DIR = ./minilibx_mms_20200219/

# local
# MLX_NAME = libmlx.a
# MLX_DIR = /usr/local/lib/

MLX_LIB = $(MLX_DIR)$(MLX_NAME)

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

# local version의 mlx library 사용시, 'make clean -C $(MLX_DIR)'는 주석처리한다.
clean :
	rm -f $(OBJS)
	make clean -C $(MLX_DIR)

# mms version의 mlx library 사용시, 복사한 library도 삭제한다.
fclean : clean
	# rm -f $(MLX_NAME)
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS) $(MLX_LIB)
	$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) -o $@

# mms version의 mlx library 사용시, library를 루트 위치에 복사해줘야 한다.
$(MLX_LIB) :
	make -C $(MLX_DIR)
	# cp $(MLX_DIR)$(MLX_NAME) $(MLX_NAME)

.PHONY :
	all clean fclean re
```

# 참고

[Events](https://harm-smits.github.io/42docs/libs/minilibx/events.html)

[후킹 - 위키백과, 우리 모두의 백과사전](https://ko.wikipedia.org/wiki/%ED%9B%84%ED%82%B9)

[[So_long] thanks for all the 'bird'](https://velog.io/@augus-xury/Solong-%EA%B8%B0%EC%B4%88-%EA%B0%9C%EB%85%90-%EC%9E%A1%EA%B8%B0-ft.-mlx)
