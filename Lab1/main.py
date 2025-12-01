import glfw
import OpenGL.GL as gl

def main():

    if not glfw.init():
        return
    window = glfw.create_window(640, 480, "Hello World", None, None)
    vertices = (
        0, 0.5, 0,
        -0.5, -0.5, 0,
        0.5, -0.5, 0)
    dtype = 'float32'
    if not window:
        glfw.terminate()
        return
    glfw.make_context_current(window)

    VAO = gl.glGenVertexArrays(1)
    VBO = gl.glGenBuffers(1)
    gl.glBindVertexArray(VAO)
    gl.glBindBuffer(gl.GL_ARRAY_BUFFER, VBO)
    gl.glBufferData(gl.GL_ARRAY_BUFFER, vertices.nbytes, vertices, gl.GL_STATIC_DRAW)
    gl.glVertexAttribPointer(0, 3, gl.GL_FLOAT, gl.GL_FALSE, 0, ctypes.c_void_p(0))
    gl.glEnableVertexAttribArray(0)
    vertex_shader = ""

    
    while not glfw.window_should_close(window):
        glfw.poll_events()
        glfw.swap_buffers(window)
    glfw.terminate()

if __name__ == "__main__":
    main()